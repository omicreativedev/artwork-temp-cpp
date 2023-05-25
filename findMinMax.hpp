#include <vector>
using namespace std;

template <typename T>
const T* findMinimumValue(const vector<T*>& userArtworks) {
  if (userArtworks.empty()) {
    return nullptr;
  }

  const T* minimumValue = userArtworks[0];
  for (int i = 0; i < userArtworks.size(); i++) {
    if (*userArtworks[i] < *minimumValue) {
      minimumValue = userArtworks[i];
    }
  }
  return minimumValue;
}

template <typename T>
const T* findMaximumValue(const vector<T*>& userArtworks) {
  if (userArtworks.empty()) {
    return nullptr;
  }

  const T* maximumValue = userArtworks[0];
  for (int i = 0; i < userArtworks.size(); i++) {
    if (*userArtworks[i] > *maximumValue) {
      maximumValue = userArtworks[i];
    }
  }
  return maximumValue;
}
