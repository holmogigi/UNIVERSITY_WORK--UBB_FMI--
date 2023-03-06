using Microsoft.EntityFrameworkCore;
namespace WebApplication2;

public class Database : DbContext
{
    public Database(DbContextOptions<Database> options)
        : base(options)
    {}

    public DbSet<BodyBuilder> BodyBuilders { get; set; } = null!;

}