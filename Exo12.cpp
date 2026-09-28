//Exercice 12

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>


void exercice12() {
    std::cout << "--- [Exercice 12] Classification de points avec SVM ---" << std::endl;

    // 1. Image 512x512 initialisee a 0
    int taille = 512;
    cv::Mat image = cv::Mat::zeros(taille, taille, CV_8UC3);

    // 2. Vecteur d'etiquettes
    int labels[4] = { 1, 2, 3, 4 };
    cv::Mat labelsMat(4, 1, CV_32SC1, labels);

    // 3. Matrice d'apprentissage
    float donneesApp[4][2] = { {501, 10}, {255, 10}, {501, 255}, {10, 501} };
    cv::Mat donneesAppMat(4, 2, CV_32FC1, donneesApp);

    // 4. Parametrage du SVM
    cv::Ptr<cv::ml::SVM> svm = cv::ml::SVM::create();
    svm->setType(cv::ml::SVM::C_SVC);
    svm->setKernel(cv::ml::SVM::LINEAR);
    svm->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER, 100, 1e-6));

    // 5. Apprentissage
    svm->train(donneesAppMat, cv::ml::ROW_SAMPLE, labelsMat);

    // 6. Prediction pour chaque pixel + coloration
    cv::Vec3b vert(0, 255, 0), bleu(255, 0, 0), rouge(0, 0, 255), jaune(0, 255, 255);
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            cv::Mat echantillon = (cv::Mat_<float>(1, 2) << j, i);
            float reponse = svm->predict(echantillon);

            if (reponse == 1)      image.at<cv::Vec3b>(i, j) = vert;
            else if (reponse == 2) image.at<cv::Vec3b>(i, j) = bleu;
            else if (reponse == 3) image.at<cv::Vec3b>(i, j) = rouge;
            else if (reponse == 4) image.at<cv::Vec3b>(i, j) = jaune;
        }
    }

    // 7. Afficher les points d'apprentissage et l'image resultat
    cv::circle(image, cv::Point(501, 10), 5, cv::Scalar(0, 0, 0), cv::FILLED);
    cv::circle(image, cv::Point(255, 10), 5, cv::Scalar(0, 0, 0), cv::FILLED);
    cv::circle(image, cv::Point(501, 255), 5, cv::Scalar(0, 0, 0), cv::FILLED);
    cv::circle(image, cv::Point(10, 501), 5, cv::Scalar(0, 0, 0), cv::FILLED);

    cv::imshow("Exercice 12 - Classification SVM", image);

    cv::waitKey(0);
    cv::destroyAllWindows();
    std::cout << "[INFO] Fin de l'exercice 12.\n" << std::endl;
}