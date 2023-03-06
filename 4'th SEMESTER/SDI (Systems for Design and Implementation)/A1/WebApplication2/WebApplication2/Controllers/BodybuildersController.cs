using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
namespace WebApplication2.Controllers;

[ApiController]
[Route("[controller]")]
public class BodybuildersController : ControllerBase
{
    private readonly Database _dbContext;

    public BodybuildersController(Database dbContext)
    {
        _dbContext = dbContext;
    }

    [HttpGet]
    public async Task<IActionResult> GetAll()
    {
        var bodybuilders = await _dbContext.BodyBuilders.ToListAsync();
        return Ok(bodybuilders);
    }

    [HttpGet("{id}")]
    public async Task<IActionResult> GetById(long id)
    {
        var bodybuilder = await _dbContext.BodyBuilders.FindAsync(id);
        if (bodybuilder == null)
        {
            return NotFound();
        }
        return Ok(bodybuilder);
    }

    [HttpPost]
    public async Task<IActionResult> Create(BodyBuilder bodybuilder)
    {
        _dbContext.BodyBuilders.Add(bodybuilder);
        await _dbContext.SaveChangesAsync();
        return Ok(bodybuilder);
    }

    [HttpPut("{id}")]
    public async Task<IActionResult> Update(long id, BodyBuilder bodybuilder)
    {
        if (id != bodybuilder.Id)
        {
            return BadRequest();
        }
        _dbContext.Entry(bodybuilder).State = EntityState.Modified;
        await _dbContext.SaveChangesAsync();
        return NoContent();
    }

    [HttpDelete("{id}")]
    public async Task<IActionResult> Delete(long id)
    {
        var bodybuilder = await _dbContext.BodyBuilders.FindAsync(id);
        if (bodybuilder == null)
        {
            return NotFound();
        }
        _dbContext.BodyBuilders.Remove(bodybuilder);
        await _dbContext.SaveChangesAsync();
        return NoContent();
    }
}