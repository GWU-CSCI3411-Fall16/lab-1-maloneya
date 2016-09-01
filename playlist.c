#include <stdio.h>

char* titles[]  = {"FreeBird", "YMCA", "SandStorm"};
char* artists[] = {"Lynard", "Village", "Darude"};

struct song_t 
{
	char *title;
	char *artist;
};

struct playlist_t 
{
	char *name; 
	struct node_t *head;
};

struct node_t
{
	struct node_t *next;
	struct song_t *song;
};

void print_playlist(struct playlist_t *pl) {
	int i; 
	struct node_t *current = pl->head;
	while (current != NULL) {
		printf("%s by %s \n", current->song->title,current->song->artist);
		current = current->next;
	}
}

int 
main(int argc, char* argv[])
{
	struct playlist_t pl1, pl2;
	struct song_t freebird, ymc, sand;
	struct node_t p1_s1, p1_s2, p1_s3;
	struct node_t p2_s1, p2_s2, p2_s3;

	freebird.title = titles[0];
	freebird.artist = artists[0];
	ymc.title = titles[1];
	ymc.artist = artists[1];
	sand.title = titles[2];
	sand.artist = artists[2];

	pl1.name = "70s";
	p1_s1.song = &ymc;
	p1_s1.next = &p1_s2;
	p1_s2.song = &freebird;
	p1_s2.next = NULL;

	print_playlist(&pl1);
	return 0;	
}

