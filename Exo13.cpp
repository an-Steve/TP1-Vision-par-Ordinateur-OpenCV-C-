//Exercice 13 : Lecture video et interface graphique

#include <iostream>
#include <opencv2/opencv.hpp>


void exercice13() {
    std::cout << "--- [Exercice 13] Lecture video et interface graphique ---" << std::endl;

    // 1. Ouvrir et verifier le flux video.mp4
    cv::VideoCapture capture(R"(C:\Users\anton\Desktop\Master 2 IA\Vision par ordinateur\TP1\video\video.mp4)");
    if (!capture.isOpened()) {
        std::cerr << "[ERREUR] Impossible d'ouvrir video.mp4 !" << std::endl;
        return;
    }

    // 2. Fenetre graphique + nombre d'images du flux
    const std::string nomFenetre = "Exercice 13 - Lecture video";
    cv::namedWindow(nomFenetre, cv::WINDOW_AUTOSIZE);
    int nbImagesTotal = (int)capture.get(cv::CAP_PROP_FRAME_COUNT);
    std::cout << "[INFO] Nombre d'images dans le flux : " << nbImagesTotal << std::endl;

    // 3. Curseur de progression (callback lambda pour repositionner le flux)
    int position = 0;
    cv::createTrackbar("Progression", nomFenetre, &position, nbImagesTotal,
        [](int pos, void* userdata) {
            cv::VideoCapture* cap = static_cast<cv::VideoCapture*>(userdata);
            cap->set(cv::CAP_PROP_POS_FRAMES, pos);
        }, &capture);

    cv::Mat frame;
    while (true) {
        // 4. Recuperer et verifier les images de la capture
        if (!capture.read(frame) || frame.empty()) {
            std::cout << "[INFO] Fin du flux video." << std::endl;
            break;
        }

        // 5. Afficher l'image (temporisation 40 ms)
        cv::imshow(nomFenetre, frame);

        // 6. Mettre a jour le curseur de progression
        position = (int)capture.get(cv::CAP_PROP_POS_FRAMES);
        cv::setTrackbarPos("Progression", nomFenetre, position);

        int touche = cv::waitKey(40);
        if (touche == 27) break; // Echap pour quitter
    }

    capture.release();
    cv::destroyAllWindows();
    std::cout << "[INFO] Fin de l'exercice 13.\n" << std::endl;
}