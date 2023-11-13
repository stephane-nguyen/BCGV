# BCGV - Boitier Central de Gestion de la Voiture

## Description

Le Boitier Central de Gestion de la Voiture (BCGV) est un projet en langage C visant à assurer le bon fonctionnement du système global d'un véhicule en interagissant avec ses différents composants par le biais de la communication UDP (User Datagram Protocol).

## Installation

Pour installer et exécuter BCGV sur votre système, suivez les étapes ci-dessous :

1. **Génération des fichiers nécessaires :**
   ```
   python generator/script.py
   ```

2. **Compilation du pilote :**
   ```
   ./bin/driver
   ```

3. **Compilation du projet :**
   ```
   make
   ```

4. **Exécution de l'application :**
   ```
   ./target/app
   ```

## Configuration

Avant de lancer l'application, assurez-vous d'avoir configuré correctement les paramètres de communication UDP dans les fichiers de configuration appropriés. Vous pouvez trouver ces fichiers dans le répertoire de configuration du projet.

## Utilisation

Une fois l'application lancée, elle interagira avec les différents composants du véhicule via la communication UDP. Assurez-vous que les éléments du système sont correctement configurés et disponibles pour garantir le bon fonctionnement de BCGV.

## Détails

### Question 1

Voir les fichiers `data.csv` et `types.csv` dans le dossier generator

### Question 2

Voir le script python dans `generator/script.py`. Il génère le fichier `generated_code.a` dans le dossier `libs`

### Question 3

Voir `src/app.c`

### Question 4

Voir `src/warning_lights_states_and_events.c`.
N'a pas été fini.

### Question 5

Voir le fichier `Makefile`. Lancer le makefile avec la commande `make`

### Question 6 et 7

Voir les fichiers `encoding.c` et `decoding.c`

---

**Remarque :** Assurez-vous d'avoir les dépendances nécessaires installées sur votre système avant de suivre ces étapes d'installation. Reportez-vous à la documentation du projet pour plus d'informations.