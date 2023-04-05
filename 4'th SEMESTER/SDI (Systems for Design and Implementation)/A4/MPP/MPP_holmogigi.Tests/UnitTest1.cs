using MPP.Models;
using MPP.DTOs;
using MPP.Controllers;
using Microsoft.EntityFrameworkCore.Storage;
using Microsoft.EntityFrameworkCore;
using MPP.Database;
using Microsoft.AspNetCore.Mvc;
using Moq;
using Moq.EntityFrameworkCore;
using Microsoft.CodeAnalysis;
using System.Collections.Generic;

namespace MPP.Tests
{
    public class UnitTest1
    {
        
        [Fact]
        public void TestBodybuilderCreation()
        {
            var bodybuilder = new BodybuilderDTO
            {
                Name = "Test",
                Age = 12, 
                Weight = 120,
                Height = 180,
                Division = "Test",
            };
            Assert.Equal("Test", bodybuilder.Name);
            Assert.Equal(12, bodybuilder.Age);
            Assert.Equal(120, bodybuilder.Weight);
            Assert.Equal(180, bodybuilder.Height);
            Assert.Equal("Test", bodybuilder.Division);

            bodybuilder.Name = "TEST";
            Assert.Equal("TEST", bodybuilder.Name);
        }

        [Fact]
        public void TestCoachCreation()
        {
            var coach = new CoachDTO
            {        
                Name = "Test" ,
                Age = 12,
                Rate = 120,
                GymId = 1
            };
            Assert.Equal("Test", coach.Name);
            Assert.Equal(12, coach.Age);
            Assert.Equal(120, coach.Rate);
            Assert.Equal(1, coach.GymId);

            coach.Age = 13;
            Assert.Equal(13, coach.Age);
        }

        [Fact]
        public void TestGymCreation()
        {
            var gym = new GymDTO
            {
                Name= "Test" ,
                Location = "Test",
                Memembership = 123,
                Grade = 12
            };
            Assert.Equal("Test", gym.Name);
            Assert.Equal("Test", gym.Location);
            Assert.Equal(123, gym.Memembership);
            Assert.Equal(12, gym.Grade);

            gym.Memembership = 1234;
            Assert.Equal(1234, gym.Memembership);
        }
    

        [Fact]
        public async Task Test1()
        {
           
            var bodyvuilders = new List<Bodybuilder>
            {
                    new Bodybuilder
                {
                    Name = "Test",
                    Age = 12,
                    Weight = 120,
                    Height = 180,
                    Division = "Test",
                },

                    new Bodybuilder
                {
                    Name = "Test",
                    Age = 15,
                    Weight = 120,
                    Height = 180,
                    Division = "Test",
                },

                     new Bodybuilder
                {
                    Name = "Test",
                    Age = 17,
                    Weight = 120,
                    Height = 180,
                    Division = "Test",
                }

            }.AsQueryable();

            var mockContext = new Mock<BodyBuildersDatabasesContext>();
            mockContext.Setup(b => b.Bodybuilders).ReturnsDbSet(bodyvuilders);
            
            var contr = new BodyBuildersController(mockContext.Object);

            var result = await contr.FilterAge(14);

            var viewResult = Assert.IsType<ActionResult<IEnumerable<BodybuilderDTO>>>(result);

            var model = Assert.IsAssignableFrom<IEnumerable<BodybuilderDTO>>(viewResult.Value);

            Assert.Equal(2, model.Count());
        }

        [Fact]
        public async Task Test2()
        {
            var gym = new List<Gym>
            {
                    new Gym
                {
                    Id = 1,
                    Name= "Test" ,
                    Location = "Test",
                    Memembership = 123,
                    Grade = 9
                },

                    new Gym
                {
                    Id = 2,
                    Name= "Test" ,
                    Location = "Test",
                    Memembership = 123,
                    Grade = 9
                },

                     new Gym
                {
                     Id = 3,
                     Name= "Test" ,
                     Location = "Test",
                     Memembership = 123,
                     Grade = 7
                }

            }.AsQueryable();


            
            var mockContext = new Mock<BodyBuildersDatabasesContext>();
            mockContext.Setup(G => G.Gyms).ReturnsDbSet(gym);

            var contr = new GymController(mockContext.Object);

            var result = await contr.FilterGrade(8);

            var viewResult = Assert.IsType<ActionResult<IEnumerable<GymDTO>>>(result);

            var model = Assert.IsAssignableFrom<IEnumerable<GymDTO>>(viewResult.Value);

            Assert.Equal(2, model.Count());
        }

    }
}