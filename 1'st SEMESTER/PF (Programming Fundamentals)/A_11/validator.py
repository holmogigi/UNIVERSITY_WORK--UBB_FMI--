class Validator:
    @staticmethod
    def validate_collum(collum):
        if collum.isdigit():
            if int(collum)>=1 and int(collum)<=7:
                return 1
        return 0
