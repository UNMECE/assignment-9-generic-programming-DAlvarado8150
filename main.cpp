
#include <iostream>
#include <stdexcept>

template <typename T>
class GenericArray
{
private:
T* data;
int length;

public:
GenericArray(){
 data = nullptr;
 length = 0;
}

~GenericArray(){
    delete[] data;
}

void addElement(T value)
{
T* newData = new T[length + 1];
for(int i=0;i<length;i++)
newData[i] = data[i];

newData[length] = value;

delete[] data;
data = newData;
length++;
}

T at(int index) const
{
if(index < 0 || index >= length)
throw std::out_of_range("bad index");

return data[index];
}

int size() const { return length; }

T sum() const
{
T total = T();
for(int i = 0;i < length;i++)
total += data[i];
return total;
}

T max() const
{
if(length == 0)
throw std::runtime_error("empty");

T m = data[0];
for(int i=1;i<length;i++)
if(data[i] > m)
m = data[i];

return m;
}

T min() const
{
if(length == 0)
throw std::runtime_error("empty");

T m = data[0];
for(int i=1;i<length;i++)
if(data[i] < m)
m = data[i];

return m;
}

T* slice(int begin,int end) const
{
if(begin < 0 || end >= length || begin > end)
throw std::out_of_range("slice error");

int s = end - begin + 1;
T* arr = new T[s];

for(int i=0;i<s;i++)
arr[i] = data[begin + i];

return arr;
}
};


int main()
{
GenericArray<int> int_array;

for(int i=0;i<=12;i++)
int_array.addElement(i*2);

std::cout<<"size of array is "<<int_array.size()<<std::endl;
std::cout<<"sum of the array is "<<int_array.sum()<<std::endl;
std::cout<<"maximum and minimum of array is "
<<int_array.max()<<"\t"<<int_array.min()<<std::endl;

int* sliced_array = int_array.slice(2,4);

for(int i=0;i<3;i++)
std::cout<<sliced_array[i]<<" ";

std::cout<<std::endl;

delete[] sliced_array;
return 0;
}
