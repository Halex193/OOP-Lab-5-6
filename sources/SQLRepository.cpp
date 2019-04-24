#include "../headers/SQLRepository.h"
//#include "mysql_connection.h"
//
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>

SQLRepository::SQLRepository(const string &tutorialsTable) : Repository(tutorialsTable)
{

}

void SQLRepository::readTutorials()
{
    destroyTutorials();
//    try
//    {
//        sql::Driver *driver;
//        sql::Connection *connection;
//        sql::Statement *statement;
//        sql::ResultSet *result;
//
//        /* Create a connection */
//        driver = get_driver_instance();
//        connection = driver->connect(hostName, userName, password);
//        /* Connect to the MySQL test database */
//        connection->setSchema(schema);
//
//        statement = connection->createStatement();
//        result = statement->executeQuery(
//                "SELECT title, presenter, minutes, seconds, likes, link FROM " + tutorialsFile);
//        while (result->next())
//        {
//            Duration duration{};
//            string title = result->getString("title");
//            string presenter = result->getString("presenter");
//            duration.minutes = result->getInt("minutes");
//            duration.seconds = result->getInt("seconds");
//            int likes = result->getInt("likes");
//            string link = result->getString("link");
//            tutorials.push_back(new Tutorial{title, presenter, duration, likes, link});
//        }
//        delete result;
//        delete statement;
//        delete connection;
//
//    } catch (sql::SQLException &e)
//    {
//        cout << "SQL connection failed!";
//    }
}

void SQLRepository::writeTutorials() const
{
//    try
//    {
//        sql::Driver *driver;
//        sql::Connection *connection;
//        sql::Statement *statement;
//
//        /* Create a connection */
//        driver = get_driver_instance();
//        connection = driver->connect(hostName, userName, password);
//        /* Connect to the MySQL test database */
//        connection->setSchema(schema);
//
//        statement = connection->createStatement();
//        statement->executeQuery("TRUNCATE TABLE " + tutorialsFile);
//        for (auto &tutorial:tutorials)
//        {
//            statement->executeQuery(
//                    "INSERT INTO " + tutorialsFile + " VALUES (`" + tutorial->getTitle() + "`, `" +
//                    tutorial->getPresenter() + "`, `" + to_string(tutorial->getDuration().minutes) + "`, `" +
//                    to_string(tutorial->getDuration().seconds) + "`, `" + to_string(tutorial->getLikes()) + "`, `" +
//                    tutorial->getLink() + "`)");
//        }
//        delete statement;
//        delete connection;
//
//    } catch (sql::SQLException &e)
//    {
//        cout << "SQL connection failed!";
//    }
}