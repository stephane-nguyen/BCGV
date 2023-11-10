#!/usr/bin/python

import csv
import re
import os
import subprocess

current_directory = os.path.dirname(os.path.abspath(__file__))

typesCsvFile = f'{current_directory}/types.csv'
dataCsvFile = f'{current_directory}/data.csv'
generatedFileName = 'generated_code'
generatedFileC = f'{current_directory}/{generatedFileName}.c'
generatedFileO = f'{current_directory}/{generatedFileName}.o'
generatedFileAFolder = f'{current_directory}/../libs'
generatedFileA = f'{generatedFileAFolder}/{generatedFileName}.a'
carTypeName = 'car_data_t'
carVariableName = 'carData'

with open(typesCsvFile, 'r') as file:
    typesContent = list(csv.DictReader(file))
with open(dataCsvFile, 'r') as file:
    dataContent = list(csv.DictReader(file))

# Initialisation
rawCode = "#include <stdint.h>\n#include <stddef.h>\n\n"

# Process types
for row in typesContent:
    # print(row)
    name = row['Name']
    genre = row['Genre']
    declaration = row['Declaration']
    comment = row['Comment']

    if genre == "typedef":
        rawCode += f"{genre} {declaration} {name};\n"
    else:
        rawCode += f"typedef {genre} {declaration} {name};\n"

rawCode += "\ntypedef struct {\n"
# Process each row in the CSV
for row in dataContent:
    variableName = row['Name']
    variableType = row['Type']
    # Create a structure to hold the variable
    rawCode += f"\t{variableType} {variableName};\n"
rawCode += "}" + f" {carTypeName};\n\n"

rawCode += f"\n{carTypeName} {carVariableName};\n\n"

def get_struct_by_typename(typename):
    for row in typesContent:
        if row['Name'] == typename:
            return row['Declaration']

def extract_names_from_declaration(str):
    pattern = r'\w+\s+(\w+);'
    return re.findall(pattern, str)

def extract_values_from_declaration(str):
    pattern = r'(\w+);'
    return re.findall(pattern, str)

rawCode += f"void init_{carVariableName}() {{\n"
for row in dataContent:
    variableName = row['Name']
    variableType = row['Type']
    initValue = row['InitValue']
    # id = 0x01; lightState = TRUE;

    # if initValue start and ends with {}
    if initValue.startswith('{') and initValue.endswith('}'):
        obj = get_struct_by_typename(variableType)

        attributeNames = extract_names_from_declaration(obj)
        initValuesExtracted = extract_values_from_declaration(initValue)

        # Assert that the number of variableNames and initValues are equal
        assert len(attributeNames) == len(initValuesExtracted), "Error: number of variableNames and initValues are not equal"
    
        for i in range(len(attributeNames)):
            attribute = attributeNames[i]
            init = initValuesExtracted[i]
            rawCode += f"\t{carVariableName}.{variableName}.{attribute} = {init};\n"
    else:
        rawCode += f"\t{carVariableName}.{variableName} = {initValue};\n"
rawCode += f"}}\n"

for row in dataContent:
    variableName = row['Name']
    variableType = row['Type']

    # Generate a setter function
    rawCode += f"void set_{variableName}({variableType} new_value) {{\n\t{carVariableName}.{variableName} = new_value;\n}}\n"

    # Generate a getter function
    rawCode += f"{variableType} get_{variableName}() {{\n\treturn {carVariableName}.{variableName};\n}}\n"

with open(generatedFileC, 'w') as file:
    file.write(rawCode)
    subprocess.run(f'gcc -c {generatedFileC} -o {generatedFileO}', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    subprocess.run(f'mkdir -p {generatedFileAFolder}', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    subprocess.run(f'ar rcs {generatedFileA} {generatedFileO}', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)


print(f"C code generated and saved to '{generatedFileA}'")
