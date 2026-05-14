#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

float costFunction(float &w, float alpha, int trainingdata[][2], int size) {
  float distance = 0;
  float moment = 0;
  float scale = 0;
  float beta_1 = 0.9;
  float beta_2 = 0.999;
  float gradient;
  int inputs;

  for (int a = 0; a < size; ++a) {
    inputs += trainingdata[a][0];
  }

  for (int i = 0; i < size; i++) {
    float model_output = trainingdata[i][0] * w;
    // We have to see the distance by the model output:
    cout << "Input: " << trainingdata[i][0]
         << " | Output Expected: " << trainingdata[i][1]
         << " | Model Output: " << model_output << endl
         << "----------------------------------------------------------------"
            "------------"
         << endl;
    distance += (model_output - trainingdata[i][1]);
    gradient = 2 * trainingdata[i][0];
    moment = beta_1 * moment + (1 - beta_1) * gradient;
    scale = beta_2 * scale + (1 - beta_2) * (gradient * gradient);
  }

  cout << "The Square Error: " << (distance * distance) << "\n\n" << endl;

  w = w - (alpha / (sqrt(scale) + 1e-8)) * moment;

  return distance * distance;
}

int main() {
  // For the first, we need the training data for the model:
  static int trainingdata[][2] = {{0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 8}};
  int trainingdata_size = sizeof(trainingdata) / sizeof(trainingdata[0]);

  // We know that our training data is determined by this equation:
  // y = x * w
  // Where y is the output, x is the input and w is the parameter

  // On this moment, we need a ramdom parameter w for initialing the model,
  // then:

  // srand(time(0));

  // float w = (float)rand() / RAND_MAX;

  float w = 60.0;
  float alpha = 0.1;
  float error;
  float final_w;

  // Compare the output with the rand parameter w:

  // costFunction(w);

  // What if minimizating the w a little:
  float e = 1e-3;

  for (int i = 0; i < 2515; ++i) {
    cout << "Interation " << i + 1 << endl;
    cout << "w: " << w << endl;
    final_w = w;
    error = costFunction(w, alpha, trainingdata, trainingdata_size);

    if (error < 10000 && error > 1000) {
      alpha = 0.01;
    } else if (error < 1000 && error > 100) {
      alpha = 0.001;
    } else if (error < 100 && error > 1e-6) {
      alpha = 0.0001;
    } else if (error < 1e-6) {
      auto old_flags = cout.flags();
      auto old_precision = cout.precision();

      cout << "\nThe model learned!!! The w is " << fixed << setprecision(1)
           << final_w << endl;

      cout.flags(old_flags);
      cout.precision(old_precision);
      break;
    }
  }

  auto old_flags = cout.flags();
  auto old_precision = cout.precision();

  cout.flags(old_flags);
  cout.precision(old_precision);

  return 0;
}