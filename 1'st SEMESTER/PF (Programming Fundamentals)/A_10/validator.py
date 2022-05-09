from exceptions import *

class Validator:
    @staticmethod
    def validate_person(person):
        errors = ""
        id = person.get_id()
        name = person.get_name()
        phone = person.get_phone()
        if not id.isdigit() or int(id) <= 0:
            errors += "Invalid ID\n"
        if not name.isalpha():
            errors += "Invalid name\n"
        if phone[0] != '0' or phone[1] != '7' or len(phone) != 10 or (not phone.isdigit()):
            errors += "Invalid phone number\n"
        if len(errors) != 0:
            raise InvalidInputError

    @staticmethod
    def validate_activity(activity):
        errors = ""
        date = activity.get_date()
        time = activity.get_time()
        if not date.isdigit() or (int(date) < 1 or int(date) > 31):
            errors += "Invalid date\n"
        if not time.isdigit() or (int(time) < 1 or int(time) > 24):
            errors += "Invalid time\n"
        if len(errors) != 0:
            raise InvalidInputError