public class Pepper implements IVegetables
{
    float weight;

    public Pepper(float weight)
    {
        this.weight=weight;
    }

    @Override
    public String to_string()
    {
        return String.format("Vegetable: Pepper, Weight: %.2f kg", weight);
    }

    @Override
    public float get_weight()
    {
        return weight;
    }
}
