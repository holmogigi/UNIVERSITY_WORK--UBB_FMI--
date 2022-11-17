public class Eggplant implements IVegetables
{
    float weight;

    public Eggplant(float weight)
    {
        this.weight=weight;
    }

    @Override
    public String to_string()
    {
        return String.format("Vegetable: Eggplant, Weight: %.2f kg", weight);
    }

    @Override
    public float get_weight()
    {
        return weight;
    }
}
