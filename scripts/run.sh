#!/bin/bash

# Compiler la bibliothèque si nécessaire
make -f Makefile_master lib

# Compiler et exécuter l'application
make -f Makefile_master app

# Nettoyer les fichiers objets et exécutables
make -f Makefile_master clean

./driver