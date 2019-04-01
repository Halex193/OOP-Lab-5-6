#include <iostream>
#include <assert.h>
#include "../headers/DynamicVector.h"
#include "../headers/Repository.h"
#include "../headers/Controller.h"

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
    Repository repository{};
    repository.add(new Tutorial(
            "Learn Java 8 - Full Tutorial for Beginners",
            "Marcus Biel",
            Duration{572, 31},
            0,
            "https://www.youtube.com/watch?v=grEKMHGYyns"
    ));

    repository.add(new Tutorial(
            "Java Programming Tutorial - 17 - Constructors",
            "thenewboston",
            Duration{5, 45},
            0,
            "https://www.youtube.com/watch?v=tPFuVRbUTwA"
    ));

    repository.add(new Tutorial(
            "Java Programming",
            "Derek Banas",
            Duration{34, 29},
            0,
            "https://www.youtube.com/watch?v=WPvGqX-TXP0"
    ));
    assert(repository.getTutorials().length() == 3);
    repository.remove(new Tutorial(
            "Java Programming Tutorial - 17 - Constructors",
            "thenewboston",
            Duration{5, 45},
            0,
            "https://www.youtube.com/watch?v=tPFuVRbUTwA"
    ));
    repository.remove(new Tutorial(
            "Java Programming",
            "Derek Banas",
            Duration{34, 29},
            0,
            "https://www.youtube.com/watch?v=WPvGqX-TXP0"
    ));
    assert(repository.getTutorials().length() == 1);
    repository.update(new Tutorial(
            "Learn Java 8 - Full Tutorial for Beginners",
            "Marcus",
            Duration{0, 0},
            12,
            "https://www.youtube.com"
    ));
    assert(repository.getTutorials().length() == 1);
    assert(repository.getTutorials().get(0)->getTitle() == "Learn Java 8 - Full Tutorial for Beginners");
    assert(repository.getTutorials().get(0)->getLikes() == 12);
    cout << "Repository test passed\n";
}

void testController()
{
    Repository repository{};
    Controller controller{repository};
    controller.add(
            "Learn Java 8",
            "Marcus Biel",
            Duration{572, 31},
            0,
            "https://www.youtube.com/watch?v=grEKMHGYyns"
    );

    controller.add(
            "Java Programming Tutorial",
            "thenewboston",
            Duration{5, 45},
            0,
            "https://www.youtube.com/watch?v=tPFuVRbUTwA"
    );

    controller.add(
            "Java",
            "Derek Banas",
            Duration{34, 29},
            0,
            "https://www.youtube.com/watch?v=WPvGqX-TXP0"
    );
    assert(controller.list().length() == 14);
    controller.remove("Java Programming Tutorial");
    controller.remove("Java");
    assert(controller.list().length() == 12);
    controller.update(
            "Learn Java 8",
            "Marcus",
            Duration{0, 0},
            12,
            "https://www.youtube.com"
    );
    assert(controller.list().length() == 12);
    assert(controller.list().get(11)->getTitle() == "Learn Java 8");
    assert(controller.list().get(11)->getLikes() == 12);
    cout << "Controller test passed\n";
}

void testWatchList()
{
    Repository repository{};
    Controller controller{repository};
    controller.begin("");
    const Tutorial *tutorial1 = controller.next();
    assert(tutorial1->getTitle() == "Learn Java 8 - Full Tutorial for Beginners");
    controller.addToWatchList(tutorial1);
    assert(controller.next()->getTitle() == "Java Programming Tutorial - 17 - Constructors");
    const Tutorial *tutorial2 = controller.next();
    assert(tutorial2->getTitle() == "Java Programming");
    controller.addToWatchList(tutorial2);
    assert(controller.next()->getTitle() == "Java Tutorial");

    controller.begin("Derek Banas");
    assert(controller.next()->getTitle() == "Java Programming");
    assert(controller.next()->getTitle() == "Java Tutorial");
    assert(controller.next()->getTitle() == "Java Video Tutorial 14");
    assert(controller.next()->getTitle() == "Java Programming");

    DynamicVector<Tutorial*> watchlist = controller.watchList();
    assert(watchlist.length() == 2);
    assert(watchlist.get(0)->getTitle() == "Learn Java 8 - Full Tutorial for Beginners");
    assert(watchlist.get(1)->getTitle() == "Java Programming");

    controller.removeFromWatchList("Learn Java 8 - Full Tutorial for Beginners");
    watchlist = controller.watchList();
    assert(watchlist.get(0)->getTitle() == "Java Programming");
    watchlist.get(0)->like();
    assert(watchlist.get(0)->getLikes() == 1);
    controller.removeFromWatchList("Java Programming");
    watchlist = controller.watchList();
    assert(watchlist.length() == 0);

    cout << "Watchlist test passed\n";
}

int main()
{
    testDynamicVector();
    testRepository();
    testController();
    testWatchList();
    cout << "All tests passed\n";
}
