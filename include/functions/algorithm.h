#pragma once
#include<vector>
using namespace std;

namespace algorithm {
	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;
	};
	stats bubble_sort(vector<int>& mass) {
		int temp;
		stats cur_stat;
		for (int i = 0; i < mass.size() - 1; i++) {
			for (int j = 0; j < mass.size() - i - 1; j++) {
				cur_stat.comparison_count++;
				if (mass[j] > mass[j + 1]) {
					cur_stat.copy_count++;
					temp = mass[j];
					mass[j] = mass[j + 1];
					mass[j + 1] = temp;
				}
			}
		}
		return cur_stat;
	}
	stats shaker_sort(vector<int>& mass) {
		stats cur_stat;
		int control = static_cast<int>(mass.size() - 1);
		int left = 0, right = control;
		do {
			for (int i = left; i < right; i++) {
				cur_stat.comparison_count++;
				if (mass[i] > mass[i + 1]) {
					cur_stat.copy_count++;
					std::swap(mass[i], mass[i + 1]);
					control = i;
				}
			}
			right = control;
			for (int i = right; i > left; i--) {
				cur_stat.comparison_count++;
				if (mass[i] < mass[i - 1]) {
					cur_stat.copy_count++;
					std::swap(mass[i], mass[i - 1]);
					control = i;
				}
			}
			left = control;
		} while (left < right);
		return cur_stat;
	}
	stats comb_sort(vector<int>& mass) {
		stats cur_stat;
		double factor = 1.2473309;
		int step = mass.size() - 1;
		while (step >= 1)
		{
			for (int i = 0; i + step < mass.size(); i++)
			{
				cur_stat.comparison_count++;
				if (mass[i] > mass[i + step])
				{
					cur_stat.copy_count++;
					std::swap(mass[i], mass[i + step]);
				}
			}
			step /= factor;
		}
		return cur_stat;
	}
}