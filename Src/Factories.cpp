#include "Factories.h"
#include "Components/Components.h"
#include <time.h>

entt::entity makeBoundary(entt::registry & registry, float xPos, float yPos, float width, float height)
{
	const entt::entity e = registry.create();
	SDL_Rect rect;
	rect.x = (int)xPos; 
	rect.y = (int)yPos;
	rect.w = (int)width;
	rect.h = (int)height;
	registry.emplace<Collider>(e, ColliderLayer::CL_boundary, rect);
	return e;
}

entt::entity makePickup(entt::registry & registry)
{
	//we need a random seed since pickups use rand() to move around
	srand(time(NULL));

	const entt::entity e = registry.create();
	registry.emplace<Pickup>(e);
	registry.emplace<Sprite>(e, "Assets/pickup.png");
	registry.emplace<Transform>(e);
	registry.emplace<Collider>(e, ColliderLayer::CL_pickup);
	return e;
}

entt::entity makeGameOverText(entt::registry & registry, int ptSize, SDL_Color color)
{
	const entt::entity e1 = registry.create();
	registry.emplace<GameOverMainText>(e1);
	registry.emplace<Text>(e1, "Assets/open_sans.ttf", ptSize, color, 0, 0);

	const entt::entity e2 = registry.create();
	registry.emplace<GameOverSubText>(e2);
	registry.emplace<Text>(e2, "Assets/open_sans.ttf", (2 * ptSize) / 3, color, 0, 50);

	return e1;
}

entt::entity makeScoreText(entt::registry & registry, int ptSize, SDL_Color color)
{
	const entt::entity e = registry.create();
	registry.emplace<ScoreText>(e);
	registry.emplace<Text>(e, "Assets/open_sans.ttf", ptSize, color, -SNAKE_SCREEN_WIDTH / 2 + 24, -SNAKE_SCREEN_HEIGHT / 2 + 24);
	return e;
}

entt::entity makeSnakeHead(entt::registry& registry, float xPos, float yPos, float xScl, float yScl)
{
	const entt::entity e = registry.create();
	registry.emplace<SnakeHead>(e);
	registry.emplace<SnakePart>(e);
	registry.emplace<Sprite>(e, "Assets/snake_head.png");
	registry.emplace<Transform>(e, xPos, yPos, xScl, yScl, Direction::up);
	registry.emplace<Collider>(e, ColliderLayer::CL_snakehead);
	return e;
}

entt::entity makeSnakeTail(entt::registry& registry, float xPos, float yPos, float xScl, float yScl)
{
	const entt::entity e = registry.create();
	registry.emplace<SnakeTail>(e);
	registry.emplace<SnakePart>(e);
	registry.emplace<Sprite>(e, "Assets/snake_tail.png");
	registry.emplace<Transform>(e, xPos, yPos, xScl, yScl, Direction::up);
	registry.emplace<Collider>(e, ColliderLayer::CL_snakebody);
	return e;
}

entt::entity makeSnakeBody(entt::registry& registry, float xPos, float yPos, float xScl, float yScl)
{
	const entt::entity e = registry.create();
	registry.emplace<SnakeBody>(e);
	registry.emplace<SnakePart>(e);
	registry.emplace<Sprite>(e, "Assets/snake_body.png");
	registry.emplace<Transform>(e, xPos, yPos, xScl, yScl, Direction::up);
	registry.emplace<Collider>(e, ColliderLayer::CL_snakebody);
	return e;
}