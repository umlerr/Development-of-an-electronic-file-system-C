#define clear system("clear||@cls");
#define MAXLEN 128

/*structure of producers*/
typedef struct PRODUCER Producers;
struct PRODUCER
{
    int id;
    char name[MAXLEN];
    Producers *next;
    Producers *prev;
};


/*structure of motherboards*/
typedef struct BOARD motherboards;
struct BOARD
{
    int id;
    Producers *producer;
    char *model;
    int volume;
    int slots;
    float pci;
    float soundtype;
    int memorytypes[3];
    motherboards *next;
};

typedef enum { false, true } bool;

/*information of program, help for user*/
void info();

/*Input*/
motherboards *input(char *s, char sep, Producers **producer, int count);

/*Main menu of the program*/
void menu(motherboards *board, Producers *producer, int count);

/*Add producer to double linked list*/
void add_producer(Producers **producer, char *name);

/*Get producer from file*/
Producers *get_producer(Producers **producer, char *name);

/*Add note from file to singly linked list*/
motherboards *add(motherboards *board, motherboards *tmp);

/*menu of output catalogue*/
void menu_output(motherboards *board);

/*menu of delete node in catalogue*/
motherboards* menu_delete(motherboards *board, int count);

/*menu of edit any node in catalogue*/
void menu_edit(motherboards *board, Producers *producer, int count);

/*menu of search in catalogue*/
void menu_search(motherboards *board, Producers* producer);

/*menu of sort catalogue*/
motherboards *menu_sort(motherboards *board);

/*Save to file after the program finished*/
void save(motherboards *board);

/*header for output catalogue*/
void header();

/*output catalogue*/
void output(motherboards *board);

/*Check for correct input from keyboard*/
int input_check(char line[MAXLEN]);

/*delete node by id from catalogue*/
void deleteNode(motherboards** board, int key);

/*delete node from list of producer*/
void deleteProducer(Producers** producer, Producers* del);

/*edit any node in catalogue by any parameter*/
motherboards *edit(motherboards *current, Producers *producer, int status);

/*Producers id count*/
void producer_id(Producers* producer);

/*Output producers to edit*/
void output_producer(Producers* producer);

/*Update producer list*/
Producers* update_producer(motherboards* board, Producers* producer);

/*search nodes by any parameter*/
void search(motherboards *board, Producers* producer, int search_status);

/*comparator to to find out if a given word is a producer's name of current node*/
Producers* find_producer(Producers* producer, int id);

/*sort increasing/decreasing catalogue by any parameter */
motherboards *sort(motherboards *root, bool (*comp)(motherboards*, motherboards*, int), int n);

/*comparator to sort  catalogue by id */
bool sort_id(motherboards* a, motherboards* b, int n);

/*comparator to sort  catalogue by producer */
bool sort_producer(motherboards* a, motherboards* b, int n);

/*comparator to sort  catalogue by model */
bool sort_model(motherboards* a, motherboards* b, int n);

/*comparator to sort  catalogue by volume */
bool sort_volume(motherboards* a, motherboards* b, int n);

/*comparator to sort  catalogue by slots */
bool sort_slots(motherboards* a, motherboards* b, int n);

/*comparator to sort  catalogue by pci */
bool sort_pci(motherboards* a, motherboards* b, int n);

/*comparator to sort  catalogue by sound type */
bool sort_soundtype(motherboards* a, motherboards* b, int n);

/*comparator to sort  catalogue by memory type 1 */
bool sort_types0(motherboards* a, motherboards* b, int n);

/*comparator to sort catalogue by memory type 2 */
bool sort_types1(motherboards* a, motherboards* b, int n);

/*comparator to sort  catalogue by memory type 3 */
bool sort_types2(motherboards* a, motherboards* b, int n);

/*splitting the input string by delimiter character*/
char **simple_split(char *line, const char sep);
