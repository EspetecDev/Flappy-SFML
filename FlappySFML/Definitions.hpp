#pragma once

#define SCREEN_WIDTH 768 
#define SCREEN_HEIGHT 1024 
#define FRAMERATE 144.0f

#define SPLASH_STATE_SHOW_TIME 1.0

// Splash
#define SPLASH_SCENE_BACKGROUND_FILEPATH "../Assets/Graphics/SplashBackground.png"

// Main Menu
#define MAIN_MENU_BACKGROUND_FILEPATH "../Assets/Graphics/sky.png"
#define GAME_TITLE_FILEPATH "../Assets/Graphics/title.png"
#define PLAY_BUTTON_FILEPATH "../Assets/Graphics/PlayButton.png"

// Game State
#define GAME_STATE_BACKGROUND_FILEPATH "../Assets/Graphics/sky.png"
#define FLAPPY_FONT_FILEPATH "../Assets/Fonts/FlappyFont.ttf"
// Pipe
#define PIPE_UP_FILEPATH "../Assets/Graphics/PipeUp.png"
#define PIPE_DOWN_FILEPATH "../Assets/Graphics/PipeDown.png"
#define PIPE_SCORING_FILEPATH "../Assets/Graphics/InvisibleScoringPipe.png"
#define PIPE_SPAWN_FREQUENCY 3.0f //SECONDS
// Land
#define LAND_FILEPATH "../Assets/Graphics/Land.png"
// Bird
#define BIRD_FRAME_1_FILEPATH "../Assets/Graphics/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "../Assets/Graphics/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "../Assets/Graphics/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "../Assets/Graphics/bird-04.png"
#define BIRD_ANIMATION_DURATION 0.4f
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define HIT_SOUND_FILEPATH "../Assets/Audio/Hit.wav"
#define POINT_SOUND_FILEPATH "../Assets/Audio/Point.wav"
#define WING_SOUND_FILEPATH "../Assets/Audio/Wing.wav"

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f
#define ROTATION_SPEED 100.0f

#define PIPE_MOVEMENT_SPEED 200.0f

enum GameStates{
	eReady,
	ePlaying,
	eGameOver
};

// Game Over
#define GAME_OVER_BACKGROUND_FILEPATH "../Assets/Graphics/sky.png"
#define GAME_OVER_TITLE_FILEPATH "../Assets/Graphics/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "../Assets/Graphics/Game-Over-Body.png"
#define FLASH_SPEED 1500.0f
#define TIME_BEFORE_GAME_OVER 1.5f

#define BRONZE_MEDAL_FILEPATH "../Assets/Graphics/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "../Assets/Graphics/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "../Assets/Graphics/Gold-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "../Assets/Graphics/Platinum-Medal.png"

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 100

// Highest Score Path
#define HIGHEST_SCORE_PATH "../Resources/hs.txt"