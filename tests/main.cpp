#include <iostream>
#include <assert.h>
#include "../headers/DynamicVector.h"

using namespace std;

void testDynamicVector()
{
    DynamicVector<int> vector{};
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);
    vector.add(5);
    assert(vector.length() == 5);
    vector.removeElement(5);
    vector.removeElement(4);
    vector.removeElement(3);
    assert(vector.length() == 2);
    vector.remove(0);
    assert(vector.length() == 1);
    assert(vector.get(0) == 2);
    vector.set(6, 0);
    assert(vector.get(0) == 6);
    cout << "DynamicVector test passed\n";
}

int main()
{
    testDynamicVector();
    cout << "All tests passed\n";
}
