import csv
import random
from enum import Enum
from faker import Faker
from multiprocessing import Process

fake = Faker()
MIN_ROLE_LEVEL = 1
MAX_ROLE_LEVEL = 100

BODYBUILDER_ROLES_COUNT = 1_000_000
COACHES_COUNT = 1_000_000
GYMS_COUNT = 1_000_000
CONTESTS_COUNT = 10_000_000


def create_bodybuilder_csv():
    print("Begin create_bodybuilder_csv")

    division = ["Men_Classic_Physique", "Men_Bodybuilding", "Women_Bodybuilding", "Women_Physique"]

    with open("bodybuilder.csv", "w", newline="") as f:
        writer = csv.writer(f)

        for i in range(1, BODYBUILDER_ROLES_COUNT + 1):
            bodybuilder_name = fake.first_name()
            bodybuilder_age = random.randint(18, 50)
            bodybuilder_weight = random.randint(50, 150)
            bodybuilder_height = random.randint(150, 200)
            bodybuilder_division = random.choice(division)
            desc = "\n".join(fake.paragraphs(nb=3))

            writer.writerow([i,
                             bodybuilder_name,
                             bodybuilder_age,
                             bodybuilder_weight,
                             bodybuilder_height,
                             bodybuilder_division,
                             desc])

    print("End create_bodybuilder_csv")


def create_gyms_csv():
    print("Begin create_gyms_csv")

    with open("gyms.csv", "w", newline="") as f:
        writer = csv.writer(f)

        for i in range(1, GYMS_COUNT + 1):
            gyms_name = fake.company()
            gyms_location = fake.city()
            gyms_membership = random.randint(50, 300)
            gyms_grade = random.randint(1, 10)

            writer.writerow([i,
                             gyms_name,
                             gyms_location,
                             gyms_membership,
                             gyms_grade])

    print("End create_gyms_csv")


def create_coaches_csv():
    print("Begin create_coaches_csv")

    with open("coaches.csv", "w", newline="") as f:
        writer = csv.writer(f)

        for i in range(1, COACHES_COUNT + 1):
            coaches_name = fake.first_name()
            coaches_age = random.randint(18, 65)
            coaches_rate = random.randint(50, 1500)
            coaches_gym_id = random.randint(1, GYMS_COUNT + 1)

            writer.writerow([i,
                             coaches_name,
                             coaches_age,
                             coaches_rate,
                             coaches_gym_id])

    print("End create_coaches_csv")


def create_contests_csv():
    print("Begin create_contests_csv")

    with open("contests.csv", "w", newline="") as f:
        writer = csv.writer(f)

        for i in range(1, CONTESTS_COUNT + 1):
            contests_datetime = fake.date_time()
            contests_name = fake.last_name()
            contests_location = fake.city()

            writer.writerow([i,
                             i,
                             contests_datetime,
                             contests_name,
                             contests_location])

    print("End create_contests_csv")


if __name__ == "__main__":

    processes = []
    for func in [
        create_bodybuilder_csv,
        create_gyms_csv,
        create_coaches_csv,
        create_contests_csv,
    ]:
        p = Process(target=func)
        processes.append(p)
        p.start()

    for p in processes:
        p.join()

print("\nFinished generating data")