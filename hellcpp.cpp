using namespace std;

int scores[] = {5, 10, 20, 30}; // arrays

vector <int> numbers = {2, 3, 5}; // vectors

int x = 10;
int * ptr = &x; // pointer to x, the syntax is like the pointer ptr is pointing to the memory address of x where & shows the address to the x

class Person {
	public: 
	string name;
	int age;
};


int main() {
	
Person person;
person.name = "Naresh";
person.age = 21;

}
