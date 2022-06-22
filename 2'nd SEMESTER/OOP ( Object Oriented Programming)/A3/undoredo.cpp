#include "undoredo.h"

UndoRedoAdd::UndoRedoAdd(const Event &event, Repository &newRepo): addedEvent(event), repo(newRepo) {}

void UndoRedoAdd::undo() {
    int index = this->repo.search(this->addedEvent.get_link());
    this->repo.remove_repo(index);
}

void UndoRedoAdd::redo() {
    this->repo.add_repo(this->addedEvent);
}

UndoRedoRemove::UndoRedoRemove(const Event &event, Repository &newRepo): removedEvent(event), repo(newRepo) {}

void UndoRedoRemove::undo() {
    this->repo.add_repo(this->removedEvent);
}

void UndoRedoRemove::redo() {
    int index = this->repo.search(this->removedEvent.get_link());
    this->repo.remove_repo(index);
}

UndoRedoUpdate::UndoRedoUpdate(const Event &oldEvent, const Event &newEvent, Repository &newRepo):oldEvent(oldEvent), newEvent(newEvent), repo(newRepo) {}

void UndoRedoUpdate::undo() {
    int index = this->repo.search(this->newEvent.get_link());
    this->repo.update_repo(index, this->oldEvent);
}

void UndoRedoUpdate::redo() {
    int index = this->repo.search(this->oldEvent.get_link());
    this->repo.update_repo(index, this->newEvent);
}
