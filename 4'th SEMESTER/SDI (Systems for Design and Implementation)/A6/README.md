## Lab 6 assignment


This assignment, as well as all future ones, must be completed on your deployed applications.

You will need to:
- Use an actual database server: I recommend PostgreSQL (and MS SQL for .NET projects), but MySQL or NoSQL databases are also accepted. No embedded databases are accepted. Please **do not** attempt this assignment with SQLite, embedded H2 or anything similar as it will not be accepted.
- Populate your database with at least `1 000 000` (one million) records for each entity. Add `10 000 000` (ten million) records for the entity acting as an intermediary in the many to many relation. This should be done through SQL scripts (one or more files) that you execute outside of your application. The data should be realistic looking: don't add complete gibberish, don't add exclusively the same value for any of the attributes, don't add sequential data where it doesn't make sense etc. It's ok if there is some repetition in the data, outside of unique fields. You can use a service such as https://www.onlinedatagenerator.com/ to help you out, but you might need some manual fine-tuning. The script should execute in a reasonable amount of time. Some ideas and suggestions below:  
  - The data doesn't need to be 100% realistic. You can have a few unique values that you randomly repeat across the many records and that you concatenate things like "\_1", "\_2" etc. to. If they don't need to be unique values, you don't even have to concatenate anything to them. For non-unique attributes, you actually **want** some amount of repetition.  
  - You can generate random values for things such as age, year etc.  
  - The SQL script can have logic such as loops in it.  
  - Although the end result needs to be at least one SQL script, you can use an external program (such as a Python script) that generates the SQL file by writing stuff in it. It might be easier to have things like lists that store base values in Python / other languages compared to pure SQL. Consider using the `Faker` library for this: https://faker.readthedocs.io/en/master/. 
  - You might want to batch the inserts to make things faster: `INSERT INTO tbl_name (a, b, c) VALUES (1, 2, 3), (4, 5, 6), (7, 8, 9);`. Batches of size `1000` generally work pretty well.
  - For the many to many intermediate table, make sure that you don't repeat the same pair of related IDs (unless this makes sense in your particular case).  
- Start using migrations if you haven't already: rerunning the application or changing something in your data models should **not** drop and recreate the database.
