<p align="center">
  <img src="screenshots/logo_paris8.png" alt="Université Paris 8" width="220">
</p>

# TP1 – Vision par Ordinateur (OpenCV / C++)

Travaux pratiques de **Vision par Ordinateur** réalisés dans le cadre du **Master 2 Intelligence Artificielle** à l'**Université Paris 8 Vincennes-Saint-Denis**.

**Auteur :** ANTON NELCON Steve – M2 IIA

---

## Présentation

Ce projet regroupe 13 exercices de traitement d'images et de vision par ordinateur écrits en **C++ avec OpenCV**. Un programme principal (`main.cpp`, exercice 14) affiche un menu interactif dans la console permettant de lancer chaque exercice indépendamment.

```
===== MENU - Vision par Ordinateur TP1 =====
 1. Chargement et affichage d'une image
 2. Filtrage lineaire
 3. Lissage de l'image
 4. Morphologie mathematique
 5. Seuillage de l'image
 6. Detection de contours (Laplacien/Canny)
 7. Egalisation d'histogrammes
 8. Appariement d'images
 9. Detection de contours (findContours)
10. Enveloppe convexe
11. Appariement des descripteurs (ORB)
12. Classification de points avec SVM
13. Lecture video et interface graphique
 0. Quitter
=============================================
```

---

## Contenu des exercices

| N° | Fichier | Thème | Fonctions OpenCV principales |
|----|---------|-------|------------------------------|
| 1 | `EXO1.cpp` | Chargement et affichage d'une image | `imread`, `namedWindow`, `imshow`, `waitKey` |
| 2 | `EXO2.cpp` | Filtrage linéaire (noyau moyenneur 3×3) | `filter2D` |
| 3 | `Exo3.cpp` | Lissage : gaussien, médian, bilatéral | `GaussianBlur`, `medianBlur`, `bilateralFilter` |
| 4 | `Exo4.cpp` | Morphologie mathématique (dilatation / érosion) | `getStructuringElement`, `dilate`, `erode` |
| 5 | `Exo5.cpp` | Seuillage binaire | `cvtColor`, `threshold` |
| 6 | `Exo6.cpp` | Détection de contours (Laplacien et Canny) | `Laplacian`, `convertScaleAbs`, `Canny` |
| 7 | `Exo7.cpp` | Égalisation d'histogramme | `equalizeHist` |
| 8 | `Exo8.cpp` | Appariement d'images (template matching) | `matchTemplate`, `minMaxLoc`, `rectangle` |
| 9 | `Exo9.cpp` | Contours segmentés | `Canny`, `findContours`, `drawContours` |
| 10 | `Exo10.cpp` | Enveloppe convexe de points aléatoires | `convexHull`, `circle`, `drawContours` |
| 11 | `Exo11.cpp` | Appariement de descripteurs (ORB) | `ORB::create`, `BFMatcher`, `drawMatches` |
| 12 | `Exo12.cpp` | Classification de points avec SVM | `ml::SVM`, `train`, `predict` |
| 13 | `Exo13.cpp` | Lecture vidéo et interface graphique | `VideoCapture`, `createTrackbar`, `setTrackbarPos` |
| 14 | `main.cpp` | Menu principal | – |

---

## Prérequis

- **OpenCV 4.5.4** (version utilisée pour le développement, modules `core`, `imgproc`, `highgui`, `imgcodecs`, `videoio`, `features2d`, `ml`)
- Un compilateur C++ compatible **C++11** ou supérieur
- **Visual Studio** (configuration Release / x64) sous Windows, ou tout autre environnement (CMake, g++) correctement lié à OpenCV

---

## Structure du projet

```
.
├── main.cpp        # Exercice 14 : menu principal
├── EXO1.cpp
├── EXO2.cpp
├── Exo3.cpp
├── ...
├── Exo13.cpp
├── images/         # Images utilisées par les exercices (à fournir)
├── video/          # Vidéo utilisée par l'exercice 13 (à fournir)
├── screenshots/    # Captures d'écran du rapport (affichées dans ce README)
└── README.md
```

### Ressources nécessaires

Les fichiers suivants doivent être fournis (ils ne sont pas inclus dans le dépôt) :

| Exercice | Ressource |
|----------|-----------|
| 1 | `landscape.jpg` |
| 2 | `plane.jpg` |
| 3 | `monalisa.jpg` |
| 4 | `apple.png` |
| 5 | `tiger.jpg` |
| 6 | `building.jpg` |
| 7 | `bird.jpg` |
| 8 | `bus.jpg`, `bus_template.png` |
| 9 | `porsche.jpg` |
| 11 | `box.png`, `box_in_scene.png` |
| 13 | `video.mp4` |

Les exercices 10 et 12 génèrent leurs données eux-mêmes.

---

## Configuration des chemins

Les chemins vers les images et la vidéo sont actuellement **écrits en dur** dans chaque fichier, par exemple :

```cpp
std::string cheminImage = "C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/landscape.jpg";
```

Avant de compiler, remplacez ces chemins par ceux de votre machine (ou par un chemin relatif comme `images/landscape.jpg`).

---

## Compilation et exécution

### Avec Visual Studio

1. Créer un projet **Application console C++**.
2. Ajouter tous les fichiers `.cpp` du dépôt au projet.
3. Configurer OpenCV : dossiers *Include* et *Lib*, ainsi que les bibliothèques à lier (`opencv_world454.lib`).
4. Compiler en **Release x64** et lancer.

### Avec CMake (exemple)

```cmake
cmake_minimum_required(VERSION 3.10)
project(TP1_Vision)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

file(GLOB SOURCES "*.cpp")
add_executable(TP1 ${SOURCES})
target_link_libraries(TP1 ${OpenCV_LIBS})
```

```bash
mkdir build && cd build
cmake ..
cmake --build . --config Release
./TP1
```

---

## Utilisation

1. Lancer l'exécutable : le menu s'affiche.
2. Saisir le numéro de l'exercice souhaité puis valider avec Entrée.
3. Les résultats s'affichent dans des fenêtres OpenCV. **Appuyer sur une touche** pour les fermer et revenir au menu (pour l'exercice 13, la touche **Échap** quitte la lecture).
4. Saisir `0` pour quitter.

---

## Aperçu des résultats

Captures d'écran issues du rapport `Rapport_TD1_Vision_par_ordinateur_-_ANTON_NELCON_Steve.pdf`.

### Menu principal (exercice 14)

<img width="750" height="296" alt="image" src="https://github.com/user-attachments/assets/c50587d9-01d7-4459-8889-a8e7d6d1036d" />


### Exercice 1 – Chargement et affichage d'une image

<img width="752" height="385" alt="image" src="https://github.com/user-attachments/assets/8cdb62db-302d-4bae-9ab2-5f406fb3524c" />

### Exercice 2 – Filtrage linéaire

<img width="752" height="385" alt="image" src="https://github.com/user-attachments/assets/0be587b1-312f-452e-b042-a126079fcb81" />

### Exercice 3 – Lissage de l'image

<img width="747" height="390" alt="image" src="https://github.com/user-attachments/assets/b01e8827-c305-43cd-9615-531b5ad62726" />

### Exercice 4 – Morphologie mathématique

<img width="661" height="330" alt="image" src="https://github.com/user-attachments/assets/fce8ffb4-e000-4c58-afc2-f5f58353b2c1" />

### Exercice 5 – Seuillage de l'image

<img width="752" height="385" alt="image" src="https://github.com/user-attachments/assets/73082571-09c5-4882-b5da-f54dd7a8f6cb" />

### Exercice 6 – Détection de contours (Laplacien / Canny)

<img width="757" height="420" alt="image" src="https://github.com/user-attachments/assets/003f7d74-800a-4686-84cc-9fce912877e8" />

### Exercice 7 – Égalisation d'histogramme

<img width="755" height="320" alt="image" src="https://github.com/user-attachments/assets/489d4dba-2fe1-4042-be49-270c0433d152" />

### Exercice 8 – Appariement d'images

<img width="750" height="365" alt="image" src="https://github.com/user-attachments/assets/b4f95447-7670-42cc-b160-9924aeea5061" />

### Exercice 9 – Détection de contours (findContours)

<img width="755" height="337" alt="image" src="https://github.com/user-attachments/assets/4315ff37-cddc-42d9-bb95-8dc4081a3ade" />

### Exercice 10 – Enveloppe convexe

<img width="751" height="382" alt="image" src="https://github.com/user-attachments/assets/d702c46a-a607-454d-bf86-810157917f5e" />

### Exercice 11 – Appariement des descripteurs (ORB)

<img width="745" height="355" alt="image" src="https://github.com/user-attachments/assets/15c42521-0650-4be6-a2aa-4a5cdb9fae97" />

### Exercice 12 – Classification de points avec SVM

<img width="752" height="382" alt="image" src="https://github.com/user-attachments/assets/5a506a07-442e-40b8-a01a-6a544cd6b124" />

### Exercice 13 – Lecture vidéo et interface graphique

<img width="750" height="387" alt="image" src="https://github.com/user-attachments/assets/3adb2fce-f262-4ec5-9816-609dad4f9642" />

### Exercice 14 – Gestion d'un choix invalide dans le menu

<img width="462" height="235" alt="image" src="https://github.com/user-attachments/assets/62e215d8-5f3a-4f21-8337-8be50221c0a1" />

---

## Remarques

- L'exercice 13 utilise un pointeur de valeur dans `createTrackbar`, ce qui provoque un avertissement OpenCV (« unsafe and deprecated ») sans effet sur le fonctionnement.
- Toute saisie invalide dans le menu affiche un message d'erreur et le menu est réaffiché.

---

## Licence

Projet académique – usage pédagogique.
