import pygame
import random
import sys

pygame.init()

# Screen
WIDTH, HEIGHT = 400, 600
GROUND_HEIGHT = 100
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Flappy Birb")
clock = pygame.time.Clock()

# Fonts
font = pygame.font.SysFont(None, 40)
big_font = pygame.font.SysFont(None, 60)

# Colors
BLUE = (135, 206, 250)
GREEN = (0, 200, 0)
BROWN = (160, 82, 45)
YELLOW = (255, 255, 0)

# Bird
BIRD_WIDTH = 30
BIRD_HEIGHT = 30
bird_x = 50
bird_y = HEIGHT // 2
bird_velocity = 0
gravity = 0.5
jump_strength = -8

# Pipes
pipe_width = 60
pipe_gap = 150
pipe_velocity = 3
pipes = []

# Game variables
score = 0
frame_count = 0
game_state = "menu"  # menu, playing, game_over

def reset_game():
    global bird_y, bird_velocity, pipes, score, frame_count
    bird_y = HEIGHT // 2
    bird_velocity = 0
    pipes = []
    score = 0
    frame_count = 0

def draw_bird():
    pygame.draw.rect(screen, YELLOW, (bird_x, bird_y, BIRD_WIDTH, BIRD_HEIGHT))

def create_pipe():
    height = random.randint(100, HEIGHT - pipe_gap - GROUND_HEIGHT - 50)
    top = pygame.Rect(WIDTH, 0, pipe_width, height)
    bottom = pygame.Rect(WIDTH, height + pipe_gap, pipe_width, HEIGHT - height - pipe_gap - GROUND_HEIGHT)
    return {'top': top, 'bottom': bottom}

def draw_pipes():
    for pipe in pipes:
        pygame.draw.rect(screen, GREEN, pipe['top'])
        pygame.draw.rect(screen, GREEN, pipe['bottom'])

def draw_ground():
    pygame.draw.rect(screen, BROWN, (0, HEIGHT - GROUND_HEIGHT, WIDTH, GROUND_HEIGHT))

def check_collision():
    bird_rect = pygame.Rect(bird_x, bird_y, BIRD_WIDTH, BIRD_HEIGHT)
    for pipe in pipes:
        if bird_rect.colliderect(pipe['top']) or bird_rect.colliderect(pipe['bottom']):
            return True
    if bird_y <= 0 or bird_y + BIRD_HEIGHT >= HEIGHT - GROUND_HEIGHT:
        return True
    return False

def draw_score():
    score_text = font.render(f"Score: {score}", True, (0, 0, 0))
    screen.blit(score_text, (10, 10))

def draw_menu():
    title = big_font.render("Flappy Birb", True, (0, 0, 0))
    prompt = font.render("Press SPACE to start", True, (0, 0, 0))
    screen.blit(title, (WIDTH // 2 - title.get_width() // 2, HEIGHT // 3))
    screen.blit(prompt, (WIDTH // 2 - prompt.get_width() // 2, HEIGHT // 2))

def draw_game_over():
    over_text = big_font.render("Game Over!", True, (255, 0, 0))
    restart_text = font.render("Press R to restart", True, (0, 0, 0))
    screen.blit(over_text, (WIDTH // 2 - over_text.get_width() // 2, HEIGHT // 3))
    screen.blit(restart_text, (WIDTH // 2 - restart_text.get_width() // 2, HEIGHT // 2))

# Main 
running = True
while running:
    clock.tick(60)
    screen.fill(BLUE)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if game_state == "menu":
            if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                reset_game()
                game_state = "playing"

        elif game_state == "playing":
            if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                bird_velocity = jump_strength

        elif game_state == "game_over":
            if event.type == pygame.KEYDOWN and event.key == pygame.K_r:
                reset_game()
                game_state = "playing"

    if game_state == "menu":
        draw_menu()

    elif game_state == "playing":
        bird_velocity += gravity
        bird_y += bird_velocity

        if frame_count % 90 == 0:
            pipes.append(create_pipe())

        for pipe in pipes:
            pipe['top'].x -= pipe_velocity
            pipe['bottom'].x -= pipe_velocity

        if pipes and pipes[0]['top'].right < 0:
            pipes.pop(0)
            score += 1

        draw_bird()
        draw_pipes()
        draw_ground()
        draw_score()

        if check_collision():
            game_state = "game_over"

        frame_count += 1

    elif game_state == "game_over":
        draw_bird()
        draw_pipes()
        draw_ground()
        draw_score()
        draw_game_over()

    pygame.display.update()

pygame.quit()
sys.exit()
