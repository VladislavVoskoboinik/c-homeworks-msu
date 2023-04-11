/* template class Myset using stl vector */
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

template <class type>
class Myset {
private:
    type m;
    vector<type>vec;
    int set_size = 0;
public:

    Myset() {
        cout << "Enter size of Set:\n" << flush;
        cin >> set_size;
        cout << "Enter your set:\n" << flush;
        for(int i = 0; i < set_size; i++){
            cin >> m;
            if(find(vec.begin(), vec.end(), m) == vec.end()){
                vec.push_back(m);
            }

        }
        sort(vec.begin(), vec.end());
    }
    
    ~Myset() {
        
    }
    
    int sfind(int var){
        for(int i = 0; i < set_size; i++){
            if(var == vec[i]){
                return i;
            }
        }
        return -1;
        cout << "Number is not in Set!\n";
    }
    
    void spush(int var){
        if(sfind(var) != -1){
            cout << "Element is already in the Set!\n";
        }else{
            int prev_var = 0;
            while(vec[prev_var] < var){
                prev_var++;
            }
            prev_var--;
            for(int i = set_size; i > prev_var; i--){
                vec[i] = vec[i-1];
            }
            vec[++prev_var] = var;
            set_size++;
        }
    }
    void sprint() {
        for (int i = 0; i < set_size; i++) {
            cout << vec[i] << ' ';
        }
        cout << endl;
    }
};

int main(){
    Myset <int> st;
    st.spush(3);
    st.sprint();

    return 0;
}
