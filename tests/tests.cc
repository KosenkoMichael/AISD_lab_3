#include <gtest/gtest.h>
#include <functions/algorithm.h>

using namespace std;
using namespace algorithm;

TEST(sorts, test) {
	//fill_file(bubble_sort<int>, "C:\\Users\\79379\\Desktop\\aisd_lab_3\\graphics_data_bubble_sort.txt");
	//fill_file(shaker_sort<int>, "C:\\Users\\79379\\Desktop\\aisd_lab_3\\graphics_data_shaker_sort.txt");
	//fill_file(comb_sort<int>, "C:\\Users\\79379\\Desktop\\aisd_lab_3\\graphics_data_comb_sort.txt");

	//cout << test_sort(bubble_sort<int>, 100000, 1, 0) << endl;
	//cout << test_sort(shaker_sort<int>, 100000, 1, 0) << endl;
	//cout << test_sort(comb_sort<int>, 100000, 1, 0) << endl;

	cout << test_sort(bubble_sort<int>, 100000, 1, 1) << endl;
	cout << test_sort(shaker_sort<int>, 100000, 1, 1) << endl;
	cout << test_sort(comb_sort<int>, 100000, 1, 1) << endl;
}
