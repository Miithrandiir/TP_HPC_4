#include <cmath>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>
#include <iostream>
#include <locale>
#include <omp.h>

// Programme de visualisation de la rÃ©partition des tÃ¢ches de
// calcul sous OpenMP
// auteur : J. Dehos

template<class charT, charT sep>
class punct_facet : public std::numpunct<charT> {
protected:
    charT do_decimal_point() const { return sep; }
};


void question1(int argc, char **argv);

void question2(int argc, char **argv);

void question3(int argc, char **argv);

void question4a(int argc, char **argv);

void question4b(int argc, char **argv);

void question5(int argc, char **argv);

// output data as a grayscale PNM image
void writePnm(std::ostream &os, int width, int height,
              const std::vector<unsigned char> &data) {
    os << "P2" << std::endl;
    os << width << ' ' << height << std::endl;
    os << "255" << std::endl;
    for (unsigned char pixel: data) os << (unsigned) pixel << ' ';
}

int main(int argc, char **argv) {
    std::cout.imbue(std::locale(std::cout.getloc(), new punct_facet<char, ','>));
    /*std::cout << "Question 1.2 :" << std::endl;
    question2(argc, argv);
    std::cout << "Question 1.3 :" << std::endl;
    question3(argc, argv);
    std::cout << "Question 1.4a :" << std::endl;
    question4a(argc, argv);
    std::cout << "Question 1.4b :" << std::endl;
    question4b(argc, argv);*/
    std::cout << "Question 1.5 :" << std::endl;
    question5(argc, argv);
}

void question1(int argc, char **argv) {
    // check command line arguments
    if (argc != 4 and argc != 3) {
        std::cout << "usage; " << argv[0]
                  << " <width> <height> [PNM filename] \n";
        return;
    }

    // reserve image data
    int width = std::stoi(argv[1]);
    int height = std::stoi(argv[2]);
    std::vector<unsigned char> data(width * height);
    auto ind = [&data, width](int xx, int yy) -> unsigned char & { return data[yy * width + xx]; };

    // start chrono
    double startTime = omp_get_wtime();

    for (int i = 0; i < 1000; ++i)
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                // diagonal gradient
                // TODO remove that
                double t = (x + y) / sqrt(width * width + height * height);
                double f = 2.0;
                ind(x, y) = 127.0 * (1 + cos(2.0 * M_PI * f * t));

                // put the color of the thread
                // TODO
            }
        }

    // stop chrono
    double endTime = omp_get_wtime();
    std::cout << argv[1] << ' ' << argv[2] << ' ' << endTime - startTime
              << std::endl;

    // write image in a file
    if (argc == 4) {
        std::ofstream ofs(argv[3]);
        writePnm(ofs, width, height, data);
    }

    return;
}

void question2(int argc, char **argv) {
    // check command line arguments
    if (argc != 4 and argc != 3) {
        std::cout << "usage; " << argv[0]
                  << " <width> <height> [PNM filename] \n";
        return;
    }

    // reserve image data
    int width = std::stoi(argv[1]);
    int height = std::stoi(argv[2]);
    std::vector<unsigned char> data(width * height);
    auto ind = [&data, width](int xx, int yy) -> unsigned char & { return data[yy * width + xx]; };

    // start chrono
    double startTime = omp_get_wtime();
    for (int i = 0; i < 1000; ++i)
        // compute image data
#pragma omp parallel for num_threads(3)
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    ind(x, y) = 255 * omp_get_thread_num() / omp_get_num_threads();
                    //std::cout << "Threads : " << omp_get_num_threads() << " Color : " << (unsigned)ind(x,y) << std::endl;
                }
            }

    // stop chrono
    double endTime = omp_get_wtime();
    std::cout << argv[1] << ' ' << argv[2] << ' ' << endTime - startTime
              << std::endl;

    // write image in a file
    if (argc == 4) {
        std::ofstream ofs(argv[3]);
        writePnm(ofs, width, height, data);
    }

    return;
}

void question3(int argc, char **argv) {
    // check command line arguments
    if (argc != 4 and argc != 3) {
        std::cout << "usage; " << argv[0]
                  << " <width> <height> [PNM filename] \n";
        return;
    }

    // reserve image data
    int width = std::stoi(argv[1]);
    int height = std::stoi(argv[2]);
    std::vector<unsigned char> data(width * height);
    auto ind = [&data, width](int xx, int yy) -> unsigned char & { return data[yy * width + xx]; };

    // start chrono
    double startTime = omp_get_wtime();

    // compute image data
    for (int i = 0; i < 1000; ++i)
#pragma omp parallel for num_threads(3) schedule(static, 50)
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    ind(x, y) = 255 * omp_get_thread_num() / omp_get_num_threads();
                    //std::cout << "Threads : " << omp_get_num_threads() << " Color : " << (unsigned)ind(x,y) << std::endl;
                }
            }

    // stop chrono
    double endTime = omp_get_wtime();
    std::cout << argv[1] << ' ' << argv[2] << ' ' << endTime - startTime
              << std::endl;

    // write image in a file
    if (argc == 4) {
        std::ofstream ofs(argv[3]);
        writePnm(ofs, width, height, data);
    }

    return;
}

void question4a(int argc, char **argv) {
    // check command line arguments
    if (argc != 4 and argc != 3) {
        std::cout << "usage; " << argv[0]
                  << " <width> <height> [PNM filename] \n";
        return;
    }

    // reserve image data
    int width = std::stoi(argv[1]);
    int height = std::stoi(argv[2]);
    std::vector<unsigned char> data(width * height);
    auto ind = [&data, width](int xx, int yy) -> unsigned char & { return data[yy * width + xx]; };

    // start chrono
    double startTime = omp_get_wtime();
    for (int i = 0; i < 1000; ++i)
        // compute image data
        for (int x = 0; x < width; x++) {
#pragma omp parallel for num_threads(3)
            for (int y = 0; y < height; y++) {
                ind(x, y) = 255 * omp_get_thread_num() / omp_get_num_threads();
                //std::cout << "Threads : " << omp_get_num_threads() << " Color : " << (unsigned)ind(x,y) << std::endl;
            }
        }

    // stop chrono
    double endTime = omp_get_wtime();
    std::cout << argv[1] << ' ' << argv[2] << ' ' << endTime - startTime
              << std::endl;

    // write image in a file
    if (argc == 4) {
        std::ofstream ofs(argv[3]);
        writePnm(ofs, width, height, data);
    }

    return;
}

void question4b(int argc, char **argv) {
    // check command line arguments
    if (argc != 4 and argc != 3) {
        std::cout << "usage; " << argv[0]
                  << " <width> <height> [PNM filename] \n";
        return;
    }

    // reserve image data
    int width = std::stoi(argv[1]);
    int height = std::stoi(argv[2]);
    std::vector<unsigned char> data(width * height);
    auto ind = [&data, width](int xx, int yy) -> unsigned char & { return data[yy * width + xx]; };

    // start chrono
    double startTime = omp_get_wtime();
    for (int i = 0; i < 1000; ++i)
        // compute image data
        for (int x = 0; x < width; x++) {
#pragma omp parallel for num_threads(3) schedule(static, 50)
            for (int y = 0; y < height; y++) {
                ind(x, y) = 255 * omp_get_thread_num() / omp_get_num_threads();
                //std::cout << "Threads : " << omp_get_num_threads() << " Color : " << (unsigned)ind(x,y) << std::endl;
            }
        }

    // stop chrono
    double endTime = omp_get_wtime();
    std::cout << argv[1] << ' ' << argv[2] << ' ' << endTime - startTime
              << std::endl;

    // write image in a file
    if (argc == 4) {
        std::ofstream ofs(argv[3]);
        writePnm(ofs, width, height, data);
    }
}

void question5(int argc, char **argv) {
    // check command line arguments
    if (argc != 4 and argc != 3) {
        std::cout << "usage; " << argv[0]
                  << " <width> <height> [PNM filename] \n";
        return;
    }

    // reserve image data
    int width = std::stoi(argv[1]);
    int height = std::stoi(argv[2]);
    std::vector<unsigned char> data(width * height);
    auto ind = [&data, width](int xx, int yy) -> unsigned char & { return data[yy * width + xx]; };

    // start chrono
    double startTime = omp_get_wtime();
    for (int i = 0; i < 1000; ++i)
        // compute image data
#pragma omp parallel for num_threads(3) schedule(static, 32) collapse(2)
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    ind(x, y) = 255 * omp_get_thread_num() / omp_get_num_threads();
                    //std::cout << "Threads : " << omp_get_num_threads() << " Color : " << (unsigned)ind(x,y) << std::endl;
                }
            }

    // stop chrono
    double endTime = omp_get_wtime();
    std::cout << argv[1] << ' ' << argv[2] << ' ' << endTime - startTime
              << std::endl;

    // write image in a file
    if (argc == 4) {
        std::ofstream ofs(argv[3]);
        writePnm(ofs, width, height, data);
    }
}