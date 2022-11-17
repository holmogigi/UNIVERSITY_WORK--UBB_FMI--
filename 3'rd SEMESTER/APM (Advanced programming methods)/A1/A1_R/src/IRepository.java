public interface IRepository
{
    void add(IVegetables vegetables);
    void remove(int pos);
    IVegetables[] get_all();
    int get_size();
}
