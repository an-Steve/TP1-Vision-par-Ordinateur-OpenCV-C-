//Exercice 10 : Enveloppe convexe

#include <iostream>
#include <opencv2/opencv.hpp>

void exercice10() {
    std::cout << "--- [Exercice 10] Enveloppe convexe ---" << std::endl;

    // 1. Image 500x500
    int taille = 500;
    cv::Mat image = cv::Mat::zeros(taille, taille, CV_8UC3);

    // 2. Boucle infinie generant des points aleatoires (1/4 a 3/4 de la largeur/hauteur)
    cv::RNG rng(12345);
    std::vector<cv::Point> points;
    const int nbPointsCible = 20;

    while (true) {
        int x = rng.uniform(taille / 4, 3 * taille / 4);
        int y = rng.uniform(taille / 4, 3 * taille / 4);
        points.push_back(cv::Point(x, y));

        if ((int)points.size() >= nbPointsCible) break; // condition d'arret
    }

    // 3. Enveloppe convexe
    std::vector<cv::Point> enveloppe;
    cv::convexHull(points, enveloppe);

    // 4. Afficher tous les points generes
    for (const auto& p : points) {
        cv::circle(image, p, 4, cv::Scalar(0, 0, 255), cv::FILLED);
    }

    // 5. Tracer l'enveloppe convexe
    std::vector<std::vector<cv::Point>> enveloppeVec = { enveloppe };
    cv::drawContours(image, enveloppeVec, 0, cv::Scalar(0, 255, 0), 2);

    // 6. Afficher l'image resultat
    cv::imshow("Exercice 10 - Enveloppe convexe", image);

    cv::waitKey(0);
    cv::destroyAllWindows();
    std::cout << "[INFO] Fin de l'exercice 10.\n" << std::endl;
}