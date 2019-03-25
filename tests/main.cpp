#include <iostream>
#include <assert.h>
#include "../headers/DynamicVector.h"
#include "../headers/Repository.h"

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
    vector.remove(2);
    vector.remove(2);
    vector.remove(2);
    assert(vector.length() == 2);
    vector.remove(0);
    assert(vector.length() == 1);
    assert(vector.get(0) == 2);
    vector.set(6, 0);
    assert(vector.get(0) == 6);
    cout << "DynamicVector test passed\n";
}

void testRepository()
{
    Repository repository;
    repository.add(new Tutorial("1", "2", Duration{3, 4}, 5, "6"));
    //TODO add remaining tests
}

int main()
{
    testDynamicVector();
    testRepository();
    cout << "All tests passed\n";
}
