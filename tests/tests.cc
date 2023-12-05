#include <gtest/gtest.h>
#include <functions/algorithm.h>

using namespace std;
using namespace algorithm;

TEST(sorts, test) {
	 
	fill_file(shaker_sort<int>, "C:\\Users\\79379\\Desktop\\AISD_lab_3\\rand_data_shaker_sort.txt", 100, 2);
	fill_file(comb_sort<int>, "C:\\Users\\79379\\Desktop\\AISD_lab_3\\rand_data_comb_sort.txt", 100, 2);
	fill_file(bubble_sort<int>, "C:\\Users\\79379\\Desktop\\AISD_lab_3\\rand_data_bubble_sort.txt", 100, 2);
	/*fill_file(bubble_sort<int>, "C:\\Users\\79379\\Desktop\\AISD_lab_3\\unsorted_bubble.txt", 1, 1);
	fill_file(shaker_sort<int>, "C:\\Users\\79379\\Desktop\\AISD_lab_3\\unsorted_shaker.txt", 1, 1);
	fill_file(comb_sort<int>, "C:\\Users\\79379\\Desktop\\AISD_lab_3\\unsorted_comb.txt", 1, 1);

	fill_file(bubble_sort<int>, "C:\\Users\\79379\\Desktop\\AISD_lab_3\\sorted_bubble.txt", 1, 0);
	fill_file(shaker_sort<int>, "C:\\Users\\79379\\Desktop\\AISD_lab_3\\sorted_shaker.txt", 1, 0);
	fill_file(comb_sort<int>, "C:\\Users\\79379\\Desktop\\AISD_lab_3\\sorted_comb.txt", 1, 0);*/
	
	/*vector<string> mass = { "b","a", "e", "d", "f", "c", "i", "h", "g", "j" };
	cout << mass<<endl;
	comb_sort(mass);
	cout << mass << endl;*/

	/*vector<Banana> mass = { {12, true}, {5, false},{30, false} };
	cout << mass << endl;
	comb_sort<Banana>(mass);
	cout << mass << endl;*/
}