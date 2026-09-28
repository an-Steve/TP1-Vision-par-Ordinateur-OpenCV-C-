//Exercice 11 : Appariement des descripteurs (ORB)

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

/**
 * @brief Exercice 11 : 
 */
void exercice11() {
    std::cout << "--- [Exercice 11] Appariement des descripteurs ---" << std::endl;

    cv::Mat img1 = cv::imread("C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/box.png", cv::IMREAD_GRAYSCALE);
    cv::Mat img2 = cv::imread("C:/Users/anton/Desktop/Master 2 IA/Vision par ordinateur/TP1/TP1 images/images/box_in_scene.png", cv::IMREAD_GRAYSCALE);

    if (img1.empty() || img2.empty()) {
        std::cerr << "[ERREUR] Impossible de trouver box.png ou box_in_scene.png !" << std::endl;
        return;
    }

    // 2. Detecteur ORB + points d'interet
    cv::Ptr<cv::ORB> detecteur = cv::ORB::create();
    std::vector<cv::KeyPoint> keypoints1, keypoints2;
    detecteur->detect(img1, keypoints1);
    detecteur->detect(img2, keypoints2);

    // 3. Descripteurs
    cv::Mat descripteurs1, descripteurs2;
    detecteur->compute(img1, keypoints1, descripteurs1);
    detecteur->compute(img2, keypoints2, descripteurs2);

    // 4. Appariement Brute Force, norme L2
    cv::BFMatcher matcher(cv::NORM_L2);
    std::vector<cv::DMatch> matches;
    matcher.match(descripteurs1, descripteurs2, matches);

    // 5. Tracer les appariements
    cv::Mat imgAppariements;
    cv::drawMatches(img1, keypoints1, img2, keypoints2, matches, imgAppariements);

    cv::imshow("Exercice 11 - Appariement des descripteurs", imgAppariements);

    cv::waitKey(0);
    cv::destroyAllWindows();
    std::cout << "[INFO] Fin de l'exercice 11.\n" << std::endl;
}