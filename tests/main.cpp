#include <iostream>
#include <fstream>
#include <assert.h>
#include "../headers/Repository.h"
#include "../headers/Controller.h"
#include "../headers/algorithmUtils.h"
#include "../headers/ComparatorAscendingByTitle.h"
#include "../headers/ComparatorDescendingByDuration.h"

using namespace std;


void testRepository(const string &file)
{
    ofstream fout{file};
    fout << "";
    fout.close();
    Repository repository{file};
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
    assert(repository.getTutorials().size() == 3);
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
    assert(repository.getTutorials().size() == 1);
    repository.update(new Tutorial(
            "Learn Java 8 - Full Tutorial for Beginners",
            "Marcus",
            Duration{0, 0},
            12,
            "https://www.youtube.com"
    ));
    assert(repository.getTutorials().size() == 1);
    assert(repository.getTutorials()[0]->getTitle() == "Learn Java 8 - Full Tutorial for Beginners");
    assert(repository.getTutorials()[0]->getLikes() == 12);
    cout << "Repository test passed\n";
}

void testController(const string &file)
{
    ofstream fout{file};
    fout << "";
    fout.close();
    Repository repository{file};
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
    assert(controller.list().size() == 3);
    controller.remove("Java Programming Tutorial");
    controller.remove("Java");
    assert(controller.list().size() == 1);
    controller.update(
            "Learn Java 8",
            "Marcus",
            Duration{0, 0},
            12,
            "https://www.youtube.com"
    );
    assert(controller.list().size() == 1);
    assert(controller.list()[0]->getTitle() == "Learn Java 8");
    assert(controller.list()[0]->getLikes() == 12);
    cout << "Controller test passed\n";
}

void testWatchList(const string &file)
{
    Repository repository{"data/tutorials.csv"};
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

    vector<Tutorial *> watchlist = controller.watchList();
    assert(watchlist.size() == 2);
    assert(watchlist[0]->getTitle() == "Learn Java 8 - Full Tutorial for Beginners");
    assert(watchlist[1]->getTitle() == "Java Programming");

    controller.removeFromWatchList("Learn Java 8 - Full Tutorial for Beginners");
    watchlist = controller.watchList();
    assert(watchlist[0]->getTitle() == "Java Programming");
    watchlist[0]->like();
    assert(watchlist[0]->getLikes() == 1);
    controller.removeFromWatchList("Java Programming");
    watchlist = controller.watchList();
    assert(watchlist.size() == 0);

    cout << "Watchlist test passed\n";
}

void testTemplatedSort()
{
    vector<Tutorial> tutorialList{};
    tutorialList.emplace_back("Title7");
    tutorialList.emplace_back("Title1");
    tutorialList.emplace_back("Title2");
    tutorialList.emplace_back("Title2");
    tutorialList.emplace_back("Title5");
    ComparatorAscendingByTitle comparator = ComparatorAscendingByTitle{};
    templatedSort(tutorialList, comparator);
    assert(tutorialList[0].getTitle() == "Title1");
    assert(tutorialList[1].getTitle() == "Title2");
    assert(tutorialList[2].getTitle() == "Title2");
    assert(tutorialList[3].getTitle() == "Title5");
    assert(tutorialList[4].getTitle() == "Title7");

    tutorialList.clear();
    tutorialList.emplace_back("5", "", Duration{1, 1}, 0, "");
    tutorialList.emplace_back("4", "", Duration{1, 2}, 0, "");
    tutorialList.emplace_back("3", "", Duration{7, 8}, 0, "");
    tutorialList.emplace_back("2", "", Duration{8, 2}, 0, "");
    tutorialList.emplace_back("1", "", Duration{9, 4}, 0, "");
    ComparatorDescendingByDuration comparator2 = ComparatorDescendingByDuration{};
    templatedSort(tutorialList, comparator2);
    assert(tutorialList[0].getTitle() == "1");
    assert(tutorialList[1].getTitle() == "2");
    assert(tutorialList[2].getTitle() == "3");
    assert(tutorialList[3].getTitle() == "4");
    assert(tutorialList[4].getTitle() == "5");
}

int main()
{
    const char *file = "data/tutorialsTest.csv";
    testRepository(file);
    testController(file);
    testWatchList(file);
    testTemplatedSort();
    remove(file);
    cout << "All tests passed\n";
}
