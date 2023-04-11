/* class map using stl String */

#include <iostream>
#include <vector>

using namespace std;

template <class type_1, class type_2> class MyMap{
private:
    vector<type_1> keys;
    vector<type_2> values;
    int size;
public:
    explicit MyMap(int s = 0) : size(0), keys(0), values(0) { //explicit - чтобы не происходило неявных преобразований типов
        size = s;
        keys = vector<type_1>(size);
        values = vector<type_2>(size);
    }
    
    MyMap(const MyMap& src) {
        size = src.size;
        keys = src.keys;
        values = src.values;
    }
    
    MyMap& append(type_1 key, type_2 value) {
        keys.push_back(key);
        values.push_back(value);
        return *this;
    }
    
    type_2 operator[](type_1 key) const {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key){
                return values[i];
            }
        }
        cout << "Error in type_1!/n";
        type_2 a;
        return a;
    }
    
    type_2& operator[](type_1 key) {
        for (int i = size; i < size*2; i++) {
            if (keys[i] == key) {
                return values[i];
            }
        }
        cout << "Error in type_2!/n";
        type_2 a;
        return a;
    }
    
    friend istream& operator>>(istream& is, MyMap& r) {
        type_1 key;
        type_2 value;
        cout << "Enter key and value in k v format " << r.size << " times\n";
        for (int i = 0; i < r.size; i++) {
            cin >> key >> value;
            r.append(key, value);
        }
        return is;
    }
    
    friend ostream& operator<<(ostream& os, MyMap& r) {
        for (int i = r.size; i < r.size*2; i++) {
            os << "'" << r.keys[i] << "': " << r.values[i] << endl;
        }
        return os;
    }
};

int main(){
    MyMap<string, double> m(5);
    cin >> m;
    cout << m;
    cout << m["a"] << "\n";
    
    return 0;
}


