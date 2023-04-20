using Google.Protobuf.WellKnownTypes;
using Microsoft.EntityFrameworkCore;
using MPP.Database;
using MPP.Models;
using MySQL.Data.EntityFrameworkCore;

var builder = WebApplication.CreateBuilder(args);
builder.Services.AddControllers()
    .AddNewtonsoftJson(options => options.SerializerSettings.ReferenceLoopHandling = Newtonsoft.Json.ReferenceLoopHandling.Ignore);

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();
builder.Services.ConfigureSwaggerGen(setup =>
{
    setup.SwaggerDoc("v1", new Microsoft.OpenApi.Models.OpenApiInfo
    {
        Title = "Bodybuilder API",
        Version = "v1"
    });
});

builder.Services.AddDbContext<BodyBuildersDatabasesContext>(opt => opt.UseSqlServer(builder.Configuration.GetConnectionString("DefaultConnection")));
builder.Services.AddCors(p => p.AddPolicy("corsapp", builder =>
{
    builder.WithOrigins("*").AllowAnyMethod().AllowAnyHeader();
}));

var app = builder.Build();

app.UseSwagger();
app.UseSwaggerUI
(c=>
{
    c.SwaggerEndpoint("/swagger/v1/swagger.json", "Bodybuilder API");
    c.RoutePrefix = string.Empty;
}
);
    
app.UseHttpsRedirection();
app.UseRouting();
app.UseCors("corsapp");
app.UseAuthorization();
app.MapControllers();

app.Run();
