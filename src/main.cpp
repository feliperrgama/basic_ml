#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>

using namespace std;

void costFunction(float w) {
  int trainingdata[][2] = {{0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 8}};

  int trainingdata_size = sizeof(trainingdata) / sizeof(trainingdata[0]);
  float distance = 0;
  for (int i = 0; i < trainingdata_size; i++) {
    float model_output = trainingdata[i][0] * w;
    // We have to see the distance by the model output:
    cout << "Input: " << trainingdata[i][0]
         << " | Output Expected: " << trainingdata[i][1]
         << " | Model Output: " << model_output << endl
         << "----------------------------------------------------------------"
            "------------"
         << endl;
    distance += (model_output - trainingdata[i][1]);
  }

  cout << "The Square Mean Error: " << (distance * distance) << "\n\n" << endl;
}

int main() {
  // For the first, we need the training data for the model:

  // We know that our training data is determined by this equation:
  // y = x * w
  // Where y is the output, x is the input and w is the parameter

  // On this moment, we need a ramdom parameter w for initialing the model,
  // then:

  // srand(time(0));

  // float w = (float)rand() / RAND_MAX;

  float w = 60.0;

  // Compare the output with the rand parameter w:

  // costFunction(w);

  // What if minimizating the w a little:
  float e = 1e-3;

  for (int i = 0; i < 5; ++i) {
    cout << "w: " << w << endl;
    costFunction(w);
    w -= e;
  }

  return 0;
}