#include <math.h>
#include <iostream>
using namespace std;
void innerSort(int arr[], int size, int n) {
  if (size < 1) {
    return;
  }
  int output[size];
  int count[10] = {0};
  int exp = pow(10, n);

  for (int i = 0; i < size; i++) {
    int scannedDigit = (arr[i] / exp) % 10;
    count[scannedDigit]++;
  }
  for (int i = 1; i < 10; i++) {
    count[i] = count[i - 1] + count[i];
  }
  for (int i = size - 1; i >= 0; i--) {
    int scannedDigit = (arr[i] / exp) % 10;
    output[count[scannedDigit] - 1] = arr[i];
    count[scannedDigit]--;
  }
  for (int i = 0; i < size; i++) {
    arr[i] = output[i];
  }
}

void radixSort(int arr[], int size) {
  if (size > 0) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
    // count digits
    int maxDigits = 0;
    while (max != 0) {
      max = max / 10;
      maxDigits++;
    }
    for (int i = 0; i < maxDigits; i++) {
      innerSort(arr, size, i);
    }
  }
}

int main() {
  int list[] = {
      812, 327, 776, 728, 6,   469, 9,   663, 253, 630, 562, 64,  740, 655, 938,
      87,  912, 37,  71,  667, 113, 543, 506, 821, 470, 272, 428, 740, 878, 102,
      975, 114, 235, 722, 47,  726, 817, 4,   351, 86,  445, 306, 367, 209, 464,
      293, 243, 287, 19,  96,  184, 46,  620, 997, 335, 930, 398, 278, 268, 799,
      215, 725, 856, 750, 539, 177, 314, 642, 413, 237, 204, 822, 166, 310, 273,
      349, 614, 633, 341, 397, 319, 927, 469, 296, 826, 759, 262, 865, 305, 830,
      585, 280, 251, 669, 611, 2,   726, 22,  163, 144, 286, 284, 5,   777, 91,
      855, 676, 287, 978, 433, 220, 147, 706, 792, 364, 790, 774, 744, 970, 894,
      194, 5,   49,  769, 479, 601, 126, 321, 257, 232, 305, 787, 215, 926, 54,
      813, 266, 984, 842, 692, 678, 152, 115, 199, 991, 607, 929, 492, 909, 494,
      392, 789, 831, 61,  63,  23,  750, 207, 611, 622, 312, 488, 165, 968, 413,
      269, 682, 253, 598, 526, 41,  535, 105, 762, 983, 972, 873, 327, 894, 405,
      387, 611, 164, 619, 563, 293, 72,  829, 108, 114, 23,  456, 231, 756, 85,
      851, 291, 837, 623, 533, 875, 820, 772, 606, 213, 370, 92,  783, 958, 740,
      273, 430, 627, 725, 602, 66,  42,  319, 471, 800, 303, 677, 286, 440, 786,
      688, 796, 319, 14,  92,  695, 769, 885, 383, 928, 210, 478, 261, 446, 810,
      89,  363, 589, 171, 801, 14,  78,  808, 736, 527, 176, 564, 0,   909, 964,
      339, 221, 823, 918, 385, 321, 485, 159, 981, 887, 473, 295, 434, 873, 232,
      216, 18,  845, 335, 78,  391, 26,  611, 987, 528, 40,  681, 927, 420, 910,
      967, 204, 702, 829, 333, 263, 973, 545, 4,   923, 126, 303, 305, 159, 232,
      786, 861, 248, 444, 360, 532, 273, 351, 786, 920, 118, 934, 184, 82,  177,
      509, 490, 429, 723, 243, 644, 207, 564, 974, 249, 84,  118, 134, 512, 856,
      892, 249, 780, 137, 272, 547, 53,  863, 849, 863, 300, 753, 779, 174, 27,
      246, 248, 146, 515, 196, 709, 744, 327, 920, 728, 809, 246, 419, 293, 523,
      646, 628, 768, 304, 76,  792, 364, 635, 352, 188, 338, 338, 940, 442, 214,
      84,  357, 431, 971, 561, 739, 952, 766, 928, 459, 660, 744, 369, 643, 779,
      508, 784, 957, 57,  649, 658, 685, 102, 538, 944, 725, 885, 329, 613, 943,
      471, 834, 653, 82,  804, 803, 500, 790, 229, 185, 320, 370, 224, 406, 523,
      381, 497, 695, 977, 177, 106, 586, 299, 619, 511, 37,  438, 879, 416, 232,
      947, 889, 212, 276, 668, 326, 566, 974, 943, 561, 223, 556, 730, 801, 336,
      936, 187, 336, 905, 442, 531, 750, 931, 423, 7,   588, 255, 472, 673, 164,
      105, 910, 674, 757, 404, 144, 4,   493, 603, 519, 96,  480, 449, 993, 371,
      685, 62,  233, 13,  207, 967, 576, 352, 464, 369, 381, 849, 985, 753, 552,
      326, 303, 211, 140, 444, 104, 389, 58,  83,  515, 631, 162, 904, 46,  969,
      61,  840, 48,  529, 206, 756, 198, 743, 710, 797, 139, 847, 855, 821, 913,
      819, 704, 488, 868, 818, 951, 645, 181, 561, 854, 149, 13,  556, 620, 382,
      63,  394, 315, 540, 160, 314, 146, 501, 498, 933, 568, 951, 532, 65,  921,
      961, 781, 575, 646, 979, 255, 363, 516, 362, 865, 454, 31,  308, 173, 465,
      392, 508, 264, 815, 297, 275, 383, 687, 233, 99,  775, 605, 698, 57,  293,
      452, 464, 487, 412, 491, 196, 907, 172, 385, 831, 151, 656, 982, 946, 213,
      952, 175, 810, 711, 685, 405, 273, 521, 867, 803, 623, 748, 824, 59,  728,
      671, 275, 444, 822, 492, 552, 825, 871, 580, 447, 513, 18,  360, 780, 558,
      123, 389, 106, 116, 798, 451, 545, 513, 248, 274, 167, 867, 721, 257, 418,
      410, 893, 261, 170, 539, 545, 403, 461, 486, 3,   738, 53,  966, 83,  264,
      892, 130, 734, 607, 671, 252, 73,  379, 472, 797, 482, 283, 534, 906, 737,
      113, 712, 72,  630, 472, 30,  368, 661, 417, 992, 414, 764, 786, 984, 460,
      973, 508, 50,  382, 422, 503, 92,  914, 758, 436, 472, 438, 642, 446, 438,
      269, 142, 686, 502, 655, 975, 594, 660, 340, 276, 706, 492, 205, 13,  974,
      61,  408, 220, 839, 706, 270, 72,  353, 795, 266, 145, 689, 402, 272, 102,
      305, 562, 495, 225, 125, 450, 364, 380, 353, 166, 21,  180, 945, 22,  23,
      627, 196, 640, 37,  597, 966, 217, 606, 89,  625, 545, 744, 407, 55,  389,
      295, 344, 991, 221, 628, 24,  513, 37,  756, 744, 488, 161, 270, 952, 731,
      818, 400, 130, 303, 893, 103, 403, 61,  819, 33,  618, 99,  579, 298, 730,
      114, 850, 262, 573, 676, 373, 777, 358, 831, 262, 561, 288, 651, 882, 804,
      173, 260, 883, 732, 398, 739, 945, 707, 66,  215, 19,  701, 530, 764, 587,
      249, 424, 750, 760, 435, 248, 724, 981, 465, 223, 411, 646, 248, 88,  30,
      603, 994, 158, 23,  125, 254, 539, 477, 38,  869, 78,  657, 509, 28,  331,
      927, 247, 907, 205, 534, 817, 233, 783, 747, 737, 121, 192, 137, 44,  109,
      4,   541, 922, 917, 735, 105, 974, 956, 788, 431, 41,  856, 724, 735, 846,
      172, 194, 455, 241, 91,  972, 455, 553, 387, 908, 718, 916, 708, 980, 28,
      114, 548, 439, 620, 201, 696, 476, 621, 535, 840, 470, 535, 743, 864, 183,
      973, 890, 175, 795, 178, 887, 870, 600, 868, 357, 190, 332, 816, 460, 902,
      615, 976, 420, 968, 959, 400, 902, 559, 802, 761, 830, 664, 677, 879, 594,
      153, 683, 174, 476, 874, 218, 172, 139, 863, 816, 442, 128, 351, 659, 908,
      540, 60,  773, 627, 487, 383, 566, 556, 299, 319, 243, 431, 975, 670, 829,
      461, 23,  593, 605, 246, 737, 193, 547, 799, 963, 586, 541, 493, 39,  56,
      468, 896, 184, 321, 67,  887, 247, 268, 841, 948};
  int arrSize = (sizeof list) / (sizeof(int));
  radixSort(list, arrSize);
  for (int i = 0; i < arrSize; i++) {
    cout << list[i] << endl;
  }
}