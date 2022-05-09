#include "UI.h"
#include "Service.h"
#include "Repo.h"
#include <vector>

int main()
{
    std::vector<Event> adminvector;
    std::string filename="RepoFile.txt";
    RepoFile repo{ adminvector,filename };
    repo.initRepo();
    Service service{ repo };
    UI ui{ service };
    ui.run_app();
    return 0;
}
