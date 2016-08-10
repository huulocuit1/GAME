#pragma once
#define FRAME_RATE 60
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 480
#define BUFFER_WIDTH 272
#define BUFFER_HEIGHT 240
#define MARIO_TILE_WIDTH_STAND 12
#define MARIO_TILE_HEGHT_STAND 15
#define MATIO_TILE_WIDTH_STAND_SUPER 14
#define MATIO_TILE_HEIGHT_STAND_SUPER 27

#define NOMAL_SIZE 16
#define SUPER_SIZE_WIDTH 16
#define SUPER_SIZE_HEIGHT 26
#define VIEW_PORTY  BUFFER_HEIGHT
#define TITLE_WINDOW L"Mario_Bros"


#define GROUND 24
#define MAP1_TILE_SIZE_HEIGHT 672
#define WALK_SPEED 2.3f
#define JUMP_MAXVEROCITY 4.0f   //6.7f
#define JUMP_MINVEROCITY 3.6
#define ANIMATE_RATE 60

#define MIN_MAP1 0
#define MAX_MAP1 2848

#define MAP1 1
#define MAP2 2
#define MAP3 3

#define SPRITE_RATE_NORMAL 15
#define SPRITE_RATE_SPEED  30


#define FILE_MAP_TXT L"Images\\Map\\Background\\background.txt"
#define TILE_MAP_PNG L"Images\\Map\\Background\\titles.png"
#define MAP1_XML "Images\\Map\\Background\\mapmario.tmx"

#define  FILE_MAP2_TXT L"Images\\Map\\Background\\map2\\map2.txt"
#define TILE_MAP2_PNG L"Images\\Map\\Background\\map2\\map2.png"
#define MAP2_XML "Images\\Map\\Background\\map2\\map2.tmx"


enum PlayerState
{
	STAND,
	RUN,
	JUMP,
	DIE,
	FLIGHT,
	STOP_HERE,
	TRAN,
	HIT_,
	ACCELERATION,
	OMRUA,
	OMRUA_RUN,
	

};

enum Direction
{
	GO_LEFT,
	JUM_LEFT,
	GO_RIGHT,
	JUMP_RIGHT,
	
	
};
