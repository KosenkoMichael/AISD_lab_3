#pragma once
#include<vector>
#include<iostream>
#include<random>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

namespace algorithm {
	class Banana {
	private:
		float _len;
		bool _taste;
	public:
		Banana(float len, bool taste) : _len(len), _taste(taste) {};
		float len() const{
			return _len;
		}
		bool taste() const{
			return _taste;
		}
	};
	bool operator> (const Banana& left, const Banana& right) {
		if (left.taste() == right.taste())
			return left.len() > right.len();
		else return left.taste();
	}
	bool operator< (const Banana left, const Banana right) {
		if (left.taste() == right.taste())
			return left.len() < right.len();
		else return right.taste();
	}
	ostream& operator<<(ostream& stream, const Banana& cur) {
		stream << cur.len() << " " << cur.taste() << " ";
		return stream;
	}
	bool operator>(const std::string& str1, const std::string& str2) {
		return str1.compare(str2) > 0;
	}

	bool operator<(const std::string& str1, const std::string& str2) {
		return str1.compare(str2) < 0;
	}
	int generate_random_number(int min, int max, int seed) {
		mt19937 mt(seed);
		uniform_int_distribution<int> distribution(min, max);
		return distribution(mt);
	}
	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;
	};
	ostream& operator<<(ostream& stream, stats val) {
		stream << val.comparison_count << " " << val.copy_count << endl;
		return stream;
	}
	template<typename T>
	fstream& operator<<(fstream& stream, vector<T> val) {
		for (int i = 0; i < val.size(); i++) {
			stream << val[i];
		}
		return stream;
	}
	template<typename T>
	ostream& operator<<(ostream& stream, vector<T> val) {
		for (int i = 0; i < val.size(); i++) {
			stream << setw(3) << val[i] << " ";
		}
		return stream;
	}
	template<typename T>
	stats sort(vector<T>& mass, stats func(vector<T>&)) {
		return func(mass);
	}
	stats average(vector<stats> mass) {
		stats stat;
		for (int i = 0; i < mass.size(); i++) {
			stat.comparison_count += mass[i].comparison_count;
			stat.copy_count += mass[i].copy_count;
		}
		stat.comparison_count /= mass.size();
		stat.copy_count /= mass.size();
		return stat;
	}

	template<typename T>
	void fill_file(stats func(vector<T>&), string path, int count, int sort_type, int seed) {
		fstream file;
		file.open(path, std::ios::app);
		vector<int> vals = { 1,2,3,4,5,6,7,8,9,10,25,50,100 };
		if (file) {
			for (int i = 0; i < vals.size(); i++) {
				/*cout << vals[i] * 1000 << endl;*/
				vector<stats> res = test_sort(func, vals[i] * 1000, count, sort_type, seed);
				file << vals[i] * 1000 << " ";
				file << average(res);
			}
		}
		else {
			cout << "ERROR";
		}
		file.close();
	}

	template<typename T>
	vector<stats> test_sort(stats func(vector<T>&), int limit, int count, int mass_type, int seed) {
		/// test_sort(sort_function: *func(type of sort funtion), limit: int(mass_len), count: int(mass_count),
		//sorted_type(0 - sort; 1 - unsorted; 2 - random_shuffle): int) -> vector<stats>
		vector<stats> results;
		int seed_helper = 0;
		for (int i = 0; i <= count - 1; i++) {
			vector<int> mass;
			switch (mass_type)
			{
			case 0:
				for (int j = 0; j < limit; j++) {
					mass.push_back(j);
				}
				break;
			case 1:
				for (int j = 0; j < limit; j++) {
					mass.push_back(limit - j);
				}
				break;
			case 2:
				for (int j = 0; j < limit; j++) {
					mass.push_back(generate_random_number(1, 100, seed+seed_helper));
					seed_helper++;
				}
				break;
			}

			cout << mass<<endl;
			results.push_back(func(mass));
		}
		return results;
	}

	template<typename T>
	stats bubble_sort(vector<T>& mass) {
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
	template<typename T>
	stats shaker_sort(vector<T>& mass) {
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
	template<typename T>
	stats comb_sort(vector<T>& mass) {
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
	template<typename T>
	void heapify(std::vector<T>& arr, int n, int i, stats& stat) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		stat.comparison_count += 1;
		if (left < n && arr[left] > arr[largest]) {
			largest = left;
			stat.copy_count += 1;
		}
		stat.comparison_count += 1;
		if (right < n && arr[right] > arr[largest]) {
			largest = right;
			stat.copy_count += 1;
		}

		if (largest != i) {
			swap(arr[i], arr[largest]);
			stat.copy_count += 1;

			heapify(arr, n, largest, stat);
		}
	}
	template<typename T>
	stats heap_sort(std::vector<T>& arr) {
		int n = arr.size();
		stats stat;
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(arr, n, i, stat);

		for (int i = n - 1; i > 0; i--) {
			stat.copy_count += 1;
			swap(arr[0], arr[i]);

			heapify(arr, i, 0, stat);
		}
		return stat;
	}
	template<typename T>
	stats shell_sort(std::vector<T>& data) {
		stats stat;
		int n = data.size();
		for (int s = n / 2; s > 0; s /= 2) {
			for (int i = s; i < n; ++i) {
				stat.comparison_count += 1;
				for (int j = i - s; j >= 0 && data[j] > data[j + s]; j -= s) {
					stat.comparison_count += 1;
					stat.copy_count += 1;
					std::swap(data[j], data[j + s]);
				}
			}
		}
		return stat;
	}
}