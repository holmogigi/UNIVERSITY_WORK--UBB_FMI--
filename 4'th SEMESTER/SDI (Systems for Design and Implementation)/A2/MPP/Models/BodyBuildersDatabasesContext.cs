using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;

namespace MPP.Models;

public partial class BodyBuildersDatabasesContext : DbContext
{
   
    public BodyBuildersDatabasesContext(DbContextOptions<BodyBuildersDatabasesContext> options) : base(options)
    {}

    public DbSet<Bodybuilder> Bodybuilders { get; set; }
    public DbSet<Gym> Gyms { get; set; }
    public DbSet<Coach> Coaches { get; set; }
}
