#include <iostream>
#include <string>
#include <vector>

template <typename ... T>
auto sumElements(T ... t){
	return (t + ... );
}

template<typename T, typename... Args>
void PushToVector(std::vector<T>& v, Args&&... args)
{
  (v.push_back(std::forward<Args>(args)), ...);

  //Раскрывается в последовательность выражений через запятую вида:
  //v.push_back(std::forward<Args_1>(arg1)),
  //v.push_back(std::forward<Args_2>(arg2)),
  //....
}


int main()
{

	std::cout << "\nSum of inputed elements is = "
			  << sumElements(15,100,1,-5,25,-6,50)
			  << ".\n";

	std::vector<int> vct;
	PushToVector(vct, 1, 4, 5, 8);

	std::cout << "\nVector contain: "
			  << vct[0] << ' '
			  << vct[1] << ' '
			  << vct[2] << ' '
			  << vct[3] << ' '
			  << ".\n";	

	return 0;
}