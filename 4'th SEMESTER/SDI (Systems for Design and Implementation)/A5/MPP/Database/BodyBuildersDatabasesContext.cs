using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;
using MPP.Models;

namespace MPP.Database;

public partial class BodyBuildersDatabasesContext : DbContext
{

    public BodyBuildersDatabasesContext(DbContextOptions<BodyBuildersDatabasesContext> options) : base(options)
    { }
    public BodyBuildersDatabasesContext() { }

    public virtual DbSet<Bodybuilder> Bodybuilders { get; set; }
    public virtual DbSet<Gym> Gyms { get; set; }
    public virtual DbSet<Coach> Coaches { get; set; }
    public virtual DbSet<Contest> Contests { get; set; }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        // configure 1 to many relationship
        modelBuilder.Entity<Coach>()
        .HasOne(c => c.Gym)
        .WithMany(g => g.Coaches)
        .HasForeignKey(c => c.GymId);

        // configure many to many relationship
        modelBuilder.Entity<Contest>()
        .HasKey(c => new { c.BodybuilderId, c.CoachId });
        modelBuilder.Entity<Contest>()
            .HasOne(c => c.Coach)
            .WithMany(c => c.Contests)
            .HasForeignKey(c => c.CoachId);
        modelBuilder.Entity<Contest>()
            .HasOne(c => c.Bodybuilder)
            .WithMany(c => c.Contests)
            .HasForeignKey(c => c.BodybuilderId);

    }

}