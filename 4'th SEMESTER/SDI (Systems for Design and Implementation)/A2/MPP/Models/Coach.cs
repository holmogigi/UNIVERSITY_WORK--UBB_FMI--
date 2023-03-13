using System.ComponentModel.DataAnnotations.Schema;
namespace MPP.Models
{
    public class Coach
    {
        public int Id { set; get; }
        public string? Name { set; get; }
        public int Age { set; get; }
        public int Rate { set; get; }

        [ForeignKey("Id")]
        public Gym? Gym { set; get; }
    }
}