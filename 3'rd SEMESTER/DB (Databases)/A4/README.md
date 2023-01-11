After you finished designing your database, the development team is interested in assessing the performance of your design. To record different test configurations and results, you create the following relational structure:

Tests – holds data about different tests;
Tables – holds data about tables that can take part in tests;
TestTables – junction table between Tests and Tables (which tables take part in which tests);
Views – holds data about a set of views from the database, used to assess the performance of certain SQL queries;
TestViews – junction table between Tests and Views (which views take part in which tests);
TestRuns – contains data about different test runs;


– a test can be run multiple times; running test T involves:

-deleting the data from test T’s tables, in the order specified by the Position field in table TestTables;

-inserting data into test T’s tables in reverse deletion order; the number of records to insert into each table is stored in the NoOfRows field in table TestTables;

-evaluating test T’s views;


TestRunTables – contains performance data for INSERT operations for each table in each test run;
TestRunViews – contains performance data for each view in each test run. See example here.


Your task is to implement a set of stored procedures to run tests and store their results. Your tests must include at least 3 tables:

-a table with a single-column primary key and no foreign keys;
-a table with a single-column primary key and at least one foreign key;
-a table with a multicolumn primary key,

and 3 views:

-a view with a SELECT statement operating on one table;

-a view with a SELECT statement that operates on at least 2 different tables and contains at least one JOIN operator;

-a view with a SELECT statement that has a GROUP BY clause, operates on at least 2 different tables and contains at least one JOIN operator.
