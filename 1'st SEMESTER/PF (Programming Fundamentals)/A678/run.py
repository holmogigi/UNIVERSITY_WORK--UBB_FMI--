from src.domain import *
from src.repository import *
from src.exceptions import *
from src.services import *
from src.ui import *
from src.tests import *

pers = Repository()
act = Repository()
services = Services(pers, act)
ui = UI(services)
ui.run()