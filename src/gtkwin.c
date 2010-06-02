/***************************************************************************
 *                              RasMol 2.7.5                               *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                              13 June 2009                               *
 *                                                                         *
 *                   Based on RasMol 2.6 by Roger Sayle                    *
 * Biomolecular Structures Group, Glaxo Wellcome Research & Development,   *
 *                      Stevenage, Hertfordshire, UK                       *
 *         Version 2.6, August 1995, Version 2.6.4, December 1998          *
 *                   Copyright (C) Roger Sayle 1992-1999                   *
 *                                                                         *
 *                          and Based on Mods by                           *
 *Author             Version, Date             Copyright                   *
 *Arne Mueller       RasMol 2.6x1   May 98     (C) Arne Mueller 1998       *
 *Gary Grossman and  RasMol 2.5-ucb Nov 95     (C) UC Regents/ModularCHEM  *
 *Marco Molinaro     RasMol 2.6-ucb Nov 96         Consortium 1995, 1996   *
 *                                                                         *
 *Philippe Valadon   RasTop 1.3     Aug 00     (C) Philippe Valadon 2000   *
 *                                                                         *
 *Herbert J.         RasMol 2.7.0   Mar 99     (C) Herbert J. Bernstein    * 
 *Bernstein          RasMol 2.7.1   Jun 99         1998-2008               *
 *                   RasMol 2.7.1.1 Jan 01                                 *
 *                   RasMol 2.7.2   Aug 00                                 *
 *                   RasMol 2.7.2.1 Apr 01                                 *
 *                   RasMol 2.7.2.1.1 Jan 04                               *
 *                   RasMol 2.7.3   Feb 05                                 *
 *                   RasMol 2.7.3.1 Apr 06                                 *
 *                   RasMol 2.7.4   Nov 07                                 *
 *                   RasMol 2.7.4.1 Jan 08                                 *
 *                   RasMol 2.7.4.2 Mar 08                                 *
 *                   RasMol 2.7.5   May 09                                 *
 *                                                                         *
 * RasMol 2.7.5 incorporates changes by T. Ikonen, G. McQuillan, N. Darakev*
 * and L. Andrews (via the neartree package).  Work on RasMol 2.7.5        *
 * supported in part by grant 1R15GM078077-01 from the National Institute  *
 * of General Medical Sciences (NIGMS), U.S. National Institutes of Health *
 * and by grant ER63601-1021466-0009501 from the Office of Biological &    *
 * Environmental Research (BER), Office of Science, U. S. Department of    *
 * Energy.  RasMol 2.7.4 incorporated  changes by G. Todorov, Nan Jia,     *
 * N. Darakev, P. Kamburov, G. McQuillan, and J. Jemilawon. Work on RasMol *
 * 2.7.4 supported in part by grant 1R15GM078077-01 from the NIGMS/NIH and *
 * grant ER63601-1021466-0009501 from BER/DOE.  RasMol 2.7.3 incorporates  *
 * changes by Clarice Chigbo, Ricky Chachra, and Mamoru Yamanishi.  Work   *
 * on RasMol 2.7.3 supported in part by grants DBI-0203064, DBI-0315281    *
 * and EF-0312612 from the U.S. National Science Foundation and grant      *
 * DE-FG02-03ER63601 from BER/DOE. The content is solely the responsibility*
 * of the authors and does not necessarily represent the official views of *
 * the funding organizations.                                              *
 *                                                                         *
 * The code for use of RasMol under GTK in RasMol 2.7.4.2 and 2.7.5 was    *
 * written by Teemu Ikonen.                                                *
 *                                                                         *
 *                    and Incorporating Translations by                    *
 *  Author                               Item                     Language *
 *  Isabel Servan Martinez,                                                *
 *  Jose Miguel Fernandez Fernandez      2.6   Manual             Spanish  *
 *  Jose Miguel Fernandez Fernandez      2.7.1 Manual             Spanish  *
 *  Fernando Gabriel Ranea               2.7.1 menus and messages Spanish  *
 *  Jean-Pierre Demailly                 2.7.1 menus and messages French   *
 *  Giuseppe Martini, Giovanni Paolella, 2.7.1 menus and messages          *
 *  A. Davassi, M. Masullo, C. Liotto    2.7.1 help file          Italian  *
 *  G. Pozhvanov                         2.7.3 menus and messages Russian  *
 *  G. Todorov                           2.7.3 menus and messages Bulgarian*
 *  Nan Jia, G. Todorov                  2.7.3 menus and messages Chinese  *
 *  Mamoru Yamanishi, Katajima Hajime    2.7.3 menus and messages Japanese *
 *                                                                         *
 *                             This Release by                             *
 * Herbert J. Bernstein, Bernstein + Sons, 5 Brewster Ln, Bellport, NY, USA*
 *                       yaya@bernstein-plus-sons.com                      *
 *               Copyright(C) Herbert J. Bernstein 1998-2008               *
 *                                                                         *
 *                READ THE FILE NOTICE FOR RASMOL LICENSES                 *
 *Please read the file NOTICE for important notices which apply to this    *
 *package and for license terms (GPL or RASLIC).                           *
 ***************************************************************************/
/* gtkwin.c
 */
 
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <termios.h>
#include <gdk/gdkkeysyms.h>
#include <vte/vte.h>
#include <stdlib.h>
#include <fcntl.h>
#include <gdk-pixbuf/gdk-pixdata.h>

#define GRAPHICS
#include "rasmol.h"
#include "graphics.h"
#include "bitmaps.h"
#include "command.h"
#include "cmndline.h"
#include "molecule.h"
#include "abstree.h"
#include "render.h"
#include "multiple.h"
#include "transfor.h"
#include "vector.h"
#include "wbrotate.h"
#include "langsel.h"
#include "gtkwin.h"
#include "gtkui.h"
#include "eggfileformatchooser.h"


#define RASGTK_MINWIDTH  300
#define RASGTK_MINHEIGHT 300

typedef union {
    Long longword;
    Byte bytes[4];
} ByteTest;


#ifdef THIRTYTWOBIT
static int SwapBytes;
#endif

extern int ProcessCommand( void );

/* Widgets and containers */
GtkWidget *mainwin;
GtkWidget *mainvbox;
GtkWidget *menubar;
GtkWidget *mainvpane;
GtkWidget *ctable;
GtkWidget *canvasarea;
GtkWidget *vscrollbar;
GtkWidget *hscrollbar;
GtkWidget *termhbox;
GtkWidget *vte;

/* Export dialog and extras */
enum {
	RADIO_CURRENT,
	RADIO_640,
	RADIO_1024,
	RADIO_1600,
	RADIO_CUSTOM
};
GtkWidget *exportdialog = NULL;
GtkWidget *format_chooser = NULL;
GtkBuilder *sizebuilder = NULL;
GSList *sizeradios = NULL;
int export_x, export_y;

/* printing */
enum {
	RES_CURRENT,
	RES_150,
	RES_300
};
int print_resolution = RES_CURRENT;
GtkPrintSettings *print_settings = NULL;
GtkPageSetup *print_pagesetup = NULL;

/* other global junk */
gulong vscr_handler;
gulong hscr_handler;
gulong menu_handler;
GtkActionGroup *action_group;
GtkUIManager *ui_manager;
GtkAccelGroup *accel_group;	
guint merge_id;
gboolean dragging = FALSE;

#define ADDSIGNAL(A,B) g_signal_connect(gtk_ui_manager_get_action(ui_manager,\
(A)),"activate", G_CALLBACK(handlemenu_cb), (gpointer) &(B));

/* Magic numbers for menus */
#define FILEMENU (0<<8)
#define DISMENU  (1<<8)
#define COLMENU  (2<<8)
#define OPTMENU  (3<<8)
#define SETMENU  (4<<8)
/* #define EXPMENU  (5<<8) */
#define HELPMENU (6<<8)

/* Magic numbers for menu items */
/* for normal menu entries, the values need to be allocated */
static const int m_f_open = (FILEMENU + 1);
static const int m_f_saveas = (FILEMENU + 2);
static const int m_f_close = (FILEMENU + 3);

#define m_ofiles (FILEMENU + 7)

static const int m_d_wireframe  = (DISMENU + 1);
static const int m_d_backbone = (DISMENU + 2);
static const int m_d_sticks = (DISMENU + 3);
static const int m_d_spheres = (DISMENU + 4);
static const int m_d_ballstick = (DISMENU + 5);
static const int m_d_ribbons = (DISMENU + 6);
static const int m_d_strands = (DISMENU + 7);
static const int m_d_cartoons = (DISMENU + 8);
static const int m_d_molsurf = (DISMENU + 9);

static const int m_c_monochrome = (COLMENU + 1);
static const int m_c_cpk = (COLMENU + 2);
static const int m_c_shapely = (COLMENU + 3);
static const int m_c_group = (COLMENU + 4);
static const int m_c_chain = (COLMENU + 5);
static const int m_c_temperature = (COLMENU + 6);
static const int m_c_structure = (COLMENU + 7);
static const int m_c_user = (COLMENU + 8);
static const int m_c_model = (COLMENU + 9);
static const int m_c_alt = (COLMENU + 10);

/* for other menu entries, the values need to be allocated */
static const int m_o_slab = (OPTMENU + 1);
static const int m_o_hydrogens = (OPTMENU + 2);
static const int m_o_heteros = (OPTMENU + 3);
static const int m_o_specular = (OPTMENU + 4);
static const int m_o_shadows = (OPTMENU + 5);
static const int m_o_stereo = (OPTMENU + 6);
static const int m_o_labels = (OPTMENU + 7);

/* for radio buttons the numbers need to be constants */
#define m_s_poff (SETMENU + 1)
#define m_s_pident (SETMENU + 2)
#define m_s_pdist (SETMENU + 3)
#define m_s_pmon (SETMENU + 4)
#define m_s_pangle (SETMENU + 5)
#define m_s_ptorsion (SETMENU + 6)
#define m_s_plabel (SETMENU + 7)
#define m_s_pcentre (SETMENU + 8)
#define m_s_pcoord (SETMENU + 9)
#define m_s_pbond (SETMENU + 10)
#define m_s_rbond (SETMENU + 11)
#define m_s_rmol (SETMENU + 12)
#define m_s_rall (SETMENU + 13)

/*
static const int m_e_gif = (EXPMENU + 1);
static const int m_e_eps = (EXPMENU + 2);
static const int m_e_ppm = (EXPMENU + 3);
static const int m_e_iris = (EXPMENU + 4);
static const int m_e_rast = (EXPMENU + 5);
static const int m_e_bmp = (EXPMENU + 6);
static const int m_e_pict = (EXPMENU + 7);
*/

/* static const int m_h_about = (HELPMENU + 1); */
static const int m_h_manual = (HELPMENU + 2);
static const int m_h_register = (HELPMENU + 3);
static const int m_h_donate = (HELPMENU + 4);


gboolean handlemenu_cb(GtkAction *action, gpointer user_data)
{
	int menu;
	
	menu = *((int *)user_data);
	HandleMenu(menu);
	/* Handle the strange tristate toggle on stereo mode */
	if(menu == m_o_stereo) {
		gtk_toggle_action_set_active((GtkToggleAction *)action, UseStereo);
	}
	if( ReDrawFlag ) {
    	RefreshScreen();
    	ReDrawFlag = NextReDrawFlag;
	}
	return FALSE;
}

void radio_cb (GtkRadioAction *action, GtkRadioAction *current, gpointer user_data)
{
	gint value;

	value = gtk_radio_action_get_current_value (action);
	HandleMenu(value);
	if( ReDrawFlag ) {
    	RefreshScreen();
    	ReDrawFlag = NextReDrawFlag;
	}
}

void open_cb(GtkAction *action, gpointer user_data)
{
    static char *prevname = NULL;
    GtkWidget *opendialog = NULL;
    GtkRecentManager* rman = NULL;
    GtkFileFilter* filter = NULL;

    opendialog = gtk_file_chooser_dialog_new ("Open File",
        GTK_WINDOW(mainwin),
        GTK_FILE_CHOOSER_ACTION_OPEN,
        GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
        GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
        NULL);

    filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "Molecular structures");
    gtk_file_filter_add_pattern(filter, "*.pdb");
    gtk_file_filter_add_pattern(filter, "*.PDB");
    gtk_file_filter_add_pattern(filter, "*.mol");
    gtk_file_filter_add_pattern(filter, "*.MOL");
    gtk_file_filter_add_pattern(filter, "*.mol2");
    gtk_file_filter_add_pattern(filter, "*.xyz");
    gtk_file_filter_add_pattern(filter, "*.XYZ");
    gtk_file_filter_add_pattern(filter, "*.mop");
    gtk_file_filter_add_pattern(filter, "*.MOP");
    gtk_file_filter_add_pattern(filter, "*.mopcrt");
    gtk_file_filter_add_pattern(filter, "*.MOPCRT");
    gtk_file_filter_add_pattern(filter, "*.mopint");
    gtk_file_filter_add_pattern(filter, "*.MOPINT");
    gtk_file_filter_add_pattern(filter, "*.mopout");
    gtk_file_filter_add_pattern(filter, "*.MOPOUT");
    gtk_file_filter_add_pattern(filter, "*.alc");
    gtk_file_filter_add_pattern(filter, "*.ALC");
    gtk_file_filter_add_pattern(filter, "*.crd");
    gtk_file_filter_add_pattern(filter, "*.cor");
    gtk_file_filter_add_pattern(filter, "*.cif");
    gtk_file_filter_add_pattern(filter, "*.CIF");
    gtk_file_filter_add_pattern(filter, "*.mmcif");
    gtk_file_filter_add_pattern(filter, "*.mmCIF");
    gtk_file_filter_add_pattern(filter, "*.MMCIF");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(opendialog), filter);
    filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "All files");
    gtk_file_filter_add_pattern(filter, "*");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(opendialog), filter);

    if(prevname) {
        gtk_file_chooser_set_filename(GTK_FILE_CHOOSER (opendialog), prevname);
    }
    if (gtk_dialog_run (GTK_DIALOG (opendialog)) == GTK_RESPONSE_ACCEPT) {
        if(prevname)
            g_free (prevname);
        prevname = gtk_file_chooser_get_filename (
            GTK_FILE_CHOOSER (opendialog));
        strcpy(DataFileName, prevname);
        if(FetchFile(FormatPDB, False, prevname)) {
            char tmp[PATH_MAX+10];

            strcpy(tmp, "file://");
            if(realpath(prevname, tmp+7)) {
                rman = gtk_recent_manager_get_default();
                gtk_recent_manager_add_item(rman, tmp);
            }
            DefaultRepresentation();
            RefreshScreen();
        } else {
            ;
        }
    }

    gtk_widget_destroy (opendialog);
}

void save_cb(GtkAction *action, gpointer user_data)
{
	static char *prevname = NULL;
	GtkWidget *dialog;
	GtkWidget *question;

	dialog = gtk_file_chooser_dialog_new ("Save to a PDB file",
				      GTK_WINDOW(mainwin),
				      GTK_FILE_CHOOSER_ACTION_SAVE,
				      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
				      GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT,
				      NULL);
	gtk_dialog_set_default_response(GTK_DIALOG(dialog), GTK_RESPONSE_ACCEPT);
	if(prevname) {
		gtk_file_chooser_set_filename(GTK_FILE_CHOOSER (dialog), prevname);
		gtk_file_chooser_unselect_all(GTK_FILE_CHOOSER (dialog));
	}
	while(TRUE) {
		if (gtk_dialog_run (GTK_DIALOG (dialog)) != GTK_RESPONSE_ACCEPT) {
			break;
		} else {
			if(prevname)
				g_free (prevname);
    		        prevname = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
			if(g_file_test(prevname, G_FILE_TEST_EXISTS)) {
				gint resp;
				question = gtk_message_dialog_new(GTK_WINDOW(dialog), GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_QUESTION, GTK_BUTTONS_YES_NO, "A file named \"%s\" already exists. Do you want to replace it?", prevname);
				resp = gtk_dialog_run(GTK_DIALOG(question));
				gtk_widget_destroy (question);
				if(resp != GTK_RESPONSE_YES) {
					continue;
				}
			}				
			SavePDBMolecule(prevname);
			break;
  		}
	}
	gtk_widget_destroy (dialog);
}

/* Render the current image to a given memory buffer with a given size */
void render_buffer(Pixel *buf, int xsize, int ysize)
{	
	Pixel *old_fbuffer; 
	int old_xrange, old_yrange, old_hrange, old_wrange, old_range, old_interactive, dx;
	
	old_fbuffer = FBuffer;
	old_xrange = XRange;
	old_yrange = YRange;
	FBuffer = buf;
	XRange = xsize;
	YRange = ysize;
	
	if( (dx = XRange%4) )
    	XRange += 4-dx;
	
	old_hrange = HRange;
	old_wrange = WRange;
	old_range = Range;
	HRange = YRange>>1;	
    WRange = XRange>>1;
    Range = MinFun(XRange,YRange);
	
	ReDrawFlag |= RFReSize;
	old_interactive = Interactive;
	Interactive = False;
	RefreshScreen(); // *buf now contains the image
	Interactive = old_interactive;
	
	FBuffer = old_fbuffer;
	XRange = old_xrange;
	YRange = old_yrange;
	HRange = old_hrange;
	WRange = old_wrange;
	Range = old_range;
	
	ReDrawFlag |= RFReSize;
	RefreshScreen();
	ReDrawFlag = NextReDrawFlag;
}

gboolean sizespin_cb(GtkSpinButton button, gpointer data)
{
	GtkLabel *header = NULL;
	char header_str[128];
	
	if(gtk_toggle_button_get_active(
		GTK_TOGGLE_BUTTON(gtk_builder_get_object(sizebuilder, "size_custom"))))
	{
		export_x = gtk_spin_button_get_value_as_int(
				GTK_SPIN_BUTTON(gtk_builder_get_object(sizebuilder, "custom_x")));
		export_y = gtk_spin_button_get_value_as_int(
				GTK_SPIN_BUTTON(gtk_builder_get_object(sizebuilder, "custom_y")));
	
		header = GTK_LABEL(gtk_builder_get_object(sizebuilder, "size_header"));
		snprintf(header_str, 127, "Size: %d x %d", export_x, export_y);
		gtk_label_set_text(header, header_str);
	}
	
	return FALSE;
}

gboolean sizeradio_cb(GtkButton *button, gpointer data)
{
	int radioid;
	GtkLabel *header = NULL;
	char header_str[128];
	
	radioid = (int) data;
	
	export_x = XRange;
	export_y = YRange;
	
	switch(radioid) {
		case RADIO_CURRENT:
			break;
		case RADIO_640:
			export_x = 640;
			export_y = 480;
			break;
		case RADIO_1024:
			export_x = 1024;
			export_y = 768;
			break;
		case RADIO_1600:
			export_x = 1600;
			export_y = 1200;
			break;
		case RADIO_CUSTOM:
			export_x = gtk_spin_button_get_value_as_int(
				GTK_SPIN_BUTTON(gtk_builder_get_object(sizebuilder, "custom_x")));
			export_y = gtk_spin_button_get_value_as_int(
				GTK_SPIN_BUTTON(gtk_builder_get_object(sizebuilder, "custom_y")));
			break;
		default:
			;
	}
	
	header = GTK_LABEL(gtk_builder_get_object(sizebuilder, "size_header"));
	snprintf(header_str, 127, "Size: %d x %d", export_x, export_y);
	gtk_label_set_text(header, header_str); 
	
	return FALSE;
}


#define SZ_RADIO_ADD(NAME, VAL) \
rbut = GTK_RADIO_BUTTON(gtk_builder_get_object(sizebuilder, (NAME))); \
g_signal_connect(G_OBJECT(rbut), "clicked", G_CALLBACK(sizeradio_cb), \
((gpointer) (VAL)));

void build_exportdialog(void)
{
	GError *err = NULL;
	GtkRadioButton *rbut = NULL;
	GtkWidget *size_chooser = NULL;
	GtkWidget *extrabox = NULL;
	int icoformat;
   
	exportdialog = gtk_file_chooser_dialog_new ("Export image to a file",
					  GTK_WINDOW(mainwin),
				      GTK_FILE_CHOOSER_ACTION_SAVE,
				      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
				      GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT,
				      NULL);
   
	format_chooser = egg_file_format_chooser_new ();   
	egg_file_format_chooser_add_pixbuf_formats (
		EGG_FILE_FORMAT_CHOOSER (format_chooser), 0, NULL);
	icoformat = egg_file_format_chooser_get_format(
		EGG_FILE_FORMAT_CHOOSER (format_chooser), "a.ico");
	egg_file_format_chooser_remove_format(
		EGG_FILE_FORMAT_CHOOSER (format_chooser), icoformat);
	
	sizebuilder = gtk_builder_new();
	g_assert(sizebuilder);
	if(!gtk_builder_add_from_string(sizebuilder, sizechooser_str, -1, &err)) {
		g_message ("building size chooser failed: s", err->message);
    	g_error_free (err);
    	exit (EXIT_FAILURE);
	}

	SZ_RADIO_ADD("size_current", RADIO_CURRENT)
	SZ_RADIO_ADD("size_640", RADIO_640)
	SZ_RADIO_ADD("size_1024", RADIO_1024)
	SZ_RADIO_ADD("size_1600", RADIO_1600)
	SZ_RADIO_ADD("size_custom", RADIO_CUSTOM)

	g_signal_connect(gtk_builder_get_object(sizebuilder, "custom_x"),
		"value-changed", G_CALLBACK(sizespin_cb), NULL);
	g_signal_connect(gtk_builder_get_object(sizebuilder, "custom_y"),
		"value-changed", G_CALLBACK(sizespin_cb), NULL);
	
	size_chooser = GTK_WIDGET(gtk_builder_get_object(sizebuilder, "size_expander"));
	
	extrabox = gtk_vbox_new(FALSE, 0);
	g_assert(extrabox);
	gtk_box_pack_start(GTK_BOX(extrabox), format_chooser, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(extrabox), size_chooser, TRUE, TRUE, 10);
	gtk_widget_show_all(extrabox);
	
	gtk_file_chooser_set_extra_widget (GTK_FILE_CHOOSER (exportdialog),
					   GTK_WIDGET (extrabox));
   
	gtk_dialog_set_default_response(GTK_DIALOG(exportdialog), GTK_RESPONSE_ACCEPT);
		
}

void export_cb(GtkAction *action, gpointer user_data)
{
	static char *fname = NULL;

	if(!exportdialog) {
		build_exportdialog();
	}
	if(fname) {
		gtk_file_chooser_set_filename(GTK_FILE_CHOOSER (exportdialog), fname);
		gtk_file_chooser_unselect_all(GTK_FILE_CHOOSER (exportdialog));
	}
	if(gtk_toggle_button_get_active(
		GTK_TOGGLE_BUTTON(gtk_builder_get_object(sizebuilder, "size_current")))) 
	{
		GtkLabel *header = NULL;
		char header_str[128];
	
		export_x = XRange;
		export_y = YRange;
		header = GTK_LABEL(gtk_builder_get_object(sizebuilder, "size_header"));
		snprintf(header_str, 127, "Size: %d x %d", export_x, export_y);
		gtk_label_set_text(header, header_str);
	}
	while(TRUE) {
		GtkWidget *question;
		GdkPixbuf *pbuf;
		GError *err = NULL;
		gboolean success = TRUE;
		guint format = 0;
		gchar *formatname = NULL;
		GSList *tmplist = NULL;
	    guchar *tmpbuf;
	   
		if (gtk_dialog_run (GTK_DIALOG (exportdialog)) != GTK_RESPONSE_ACCEPT) {
			break;
		}
		
		if(fname) {
			g_free (fname);
		}
	    fname = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (exportdialog));
		if(g_file_test(fname, G_FILE_TEST_EXISTS)) {
	    	gint resp;
			question = gtk_message_dialog_new(GTK_WINDOW(exportdialog), 
				GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, 
				GTK_MESSAGE_QUESTION, GTK_BUTTONS_YES_NO, 
				"A file named \"%s\" already exists. Do you want to replace it?", 
				fname);
			resp = gtk_dialog_run(GTK_DIALOG(question));
			gtk_widget_destroy (question);
			if(resp != GTK_RESPONSE_YES) {
				continue;
			}
		}
		
		format = egg_file_format_chooser_get_format (
			EGG_FILE_FORMAT_CHOOSER(format_chooser), fname);
		if(!format) {
			char *tmp;
			question = gtk_message_dialog_new(GTK_WINDOW(exportdialog), 
				GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, 
				GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, 
				"Could not recognise format of output file \"%s\", please choose another format.", 
				((tmp = rindex(fname, '/')) != NULL) ? (tmp+1) : (fname));
			gtk_dialog_run(GTK_DIALOG(question));			   
			gtk_widget_destroy (question);
			continue;
		}
		formatname = (gchar *) egg_file_format_chooser_get_format_data(
			EGG_FILE_FORMAT_CHOOSER(format_chooser), format);
		
	    tmpbuf = g_new(guchar, 4*export_x*export_y);
	    render_buffer((Pixel *) tmpbuf, export_x, export_y); 
	    pbuf = gdk_pixbuf_new_from_data(tmpbuf,
			GDK_COLORSPACE_RGB,
			TRUE, 8,
			export_x, export_y, 4*export_x,
			NULL, NULL);
		success = gdk_pixbuf_save(pbuf, fname, formatname, &err, NULL);
	  	
		if(!success && (err != NULL) ) {
			question = gtk_message_dialog_new(GTK_WINDOW(exportdialog), 
				GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, 
				GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, "Error saving image: %s", 
				err->message);
			gtk_dialog_run(GTK_DIALOG(question));			   
			gtk_widget_destroy (question);				   
		}
		g_object_unref(pbuf);
	    g_free(tmpbuf);
	    break;
	}
	gtk_widget_hide (exportdialog);   
}

void pagesetup_cb(GtkAction *action, gpointer user_data)
{
	if (print_pagesetup == NULL) {
		print_pagesetup = gtk_page_setup_new();
	}
	print_pagesetup = gtk_print_run_page_setup_dialog(GTK_WINDOW (mainwin), print_pagesetup, print_settings);
}


/* Shuffle bytes from gdk_draw_rgb_32_image format to cairo rgb format */   
void rgb_convert(guint8 *buf, int len)
{
	int i;
	guint8 r, g, b;
	
	for(i = 0; i < 4*len; i += 4) {
		r = buf[i+0];
		g = buf[i+1];
		b = buf[i+2];
		buf[i+0] = b;
		buf[i+1] = g;
		buf[i+2] = r;
		buf[i+3] = 0xff;
	}
}


void print_draw(GtkPrintOperation *printop, GtkPrintContext *context, 
	gint pageno, gpointer user_data)
{
	cairo_t *cr;
	cairo_surface_t *sur;
	cairo_pattern_t *pat;
	cairo_matrix_t mat;
	gdouble width, height;
    guchar *tmpbuf;
    int print_x, print_y;
   	gdouble scale;

	width = gtk_print_context_get_width (context); // in mm
	height = gtk_print_context_get_height (context);
	
	switch(print_resolution) {
		case RES_150:
			print_x = (int) (150.0/25.4 * width);
			print_y = (int) (150.0/25.5 * height);
			break;
		case RES_300:
			print_x = (int) (300.0/25.4 * width);
			print_y = (int) (300.0/25.4 * height);
			break;
		default:
			print_x = XRange;
			print_y = YRange;
			break;
	}
	
	print_x &= ~3;
	print_y &= ~3;

	tmpbuf = g_new(guchar, 4*print_x*print_y);
	render_buffer((Pixel *) tmpbuf, print_x, print_y);
	rgb_convert((guint8 *) tmpbuf, print_x*print_y);

	cr = gtk_print_context_get_cairo_context (context);	
	sur = cairo_image_surface_create_for_data((unsigned char *) tmpbuf,
		CAIRO_FORMAT_RGB24, print_x, print_y, 4*print_x);
	pat = cairo_pattern_create_for_surface(sur);
	scale = ((gdouble)print_x)/width;
	cairo_matrix_init_scale (&mat, scale, scale);	
	cairo_pattern_set_matrix(pat, &mat);
	cairo_set_source(cr, pat);
	cairo_rectangle (cr, 0, 0, width, height);
 	cairo_fill (cr);
	
	cairo_pattern_destroy(pat);
	cairo_surface_destroy(sur);
    g_free(tmpbuf);
}

void print_get_res_cb(GtkPrintOperation *print, GtkWidget *widget, gpointer rb)
{
	GSList *el;
	
	el = gtk_radio_button_get_group(*((GtkRadioButton **)rb));
	while(el != NULL) {
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(el->data))) {
			print_resolution = (int) g_object_get_data(G_OBJECT(el->data), "res");
			return;
		} else
			el = el->next;
	}
	return;
}

GObject *print_build_reswidget_cb(GtkPrintOperation *operation, gpointer radio_p) 
{
	GtkBuilder *b = NULL;
	GObject *widget = NULL;
	GError *err = NULL;
	GObject *r = NULL;
	
	b = gtk_builder_new();
	if(!gtk_builder_add_from_string(b, print_resolution_str, -1, &err)) {
		g_message ("building size chooser failed: s", err->message);
    	g_error_free (err);
    	exit (EXIT_FAILURE);
	}
	r = gtk_builder_get_object(b, "res_radio1");
	g_object_set_data(r, "res", (gpointer) RES_CURRENT);
	if(print_resolution == RES_CURRENT)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r), TRUE);
	r = gtk_builder_get_object(b, "res_radio2");
	g_object_set_data(r, "res", (gpointer) RES_150);
	if(print_resolution == RES_150)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r), TRUE);	
	r = gtk_builder_get_object(b, "res_radio3");
	g_object_set_data(r, "res", (gpointer) RES_300);
	if(print_resolution == RES_300)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r), TRUE);	
	*((GObject **) radio_p) = r;
	
	widget = gtk_builder_get_object(b, "resframe");
	g_assert(widget != NULL);
	
	return widget;
}

void print_cb(GtkAction *action, gpointer user_data)
{
	GtkPrintOperation *print;
  	GtkPrintOperationResult res;
	GtkToggleButton *radio = NULL;
	
  	print = gtk_print_operation_new ();
	gtk_print_operation_set_n_pages(print, 1);
	gtk_print_operation_set_custom_tab_label(print, "Resolution");
	gtk_print_operation_set_unit(print, GTK_UNIT_MM);
	
  	g_signal_connect (print, "draw_page", G_CALLBACK (print_draw), NULL);
  	g_signal_connect (print, "create-custom-widget", G_CALLBACK (print_build_reswidget_cb), &radio);
  	g_signal_connect (print, "custom-widget-apply", G_CALLBACK (print_get_res_cb), &radio);

	if (print_pagesetup != NULL)
		gtk_print_operation_set_default_page_setup(print, print_pagesetup);
  	if (print_settings != NULL) 
    	gtk_print_operation_set_print_settings (print, print_settings);
	
  	res = gtk_print_operation_run (print, 
		GTK_PRINT_OPERATION_ACTION_PRINT_DIALOG, GTK_WINDOW (mainwin), NULL);
		
  	if (res == GTK_PRINT_OPERATION_RESULT_APPLY) {
      	if (print_settings != NULL)
        	g_object_unref (print_settings);
      	print_settings = g_object_ref (gtk_print_operation_get_print_settings (print));
    }

  	g_object_unref (print);
}


void DisplayAboutDLG(void)
{
  
}

void about_cb(GtkAction *action, gpointer user_data)
{
	gchar *authors[] = { "Roger Sayle", NULL };
	gtk_show_about_dialog(GTK_WINDOW(mainwin),
		"authors", authors,
		"comments", "Molecular Renderer",
		"copyright", 
"Copyright (C)\n\
Roger Sayle 1992-1999\n\
Herbert J. Bernstein 1998-2008\n\
",
		"license", "GPL",
		"logo-icon-name", "/usr/share/pixmaps/rasmol.xpm",
		"version", VERSION,
		"website", "http://rasmol.org/",
		NULL);
}

void build_window(void)
{
	GList *vlist;
	GtkAction *a;
	gint x, y;
	
	vlist = gtk_container_get_children(GTK_CONTAINER(mainvbox));
	while(vlist) {
		g_object_ref(vlist->data);
		gtk_container_remove(GTK_CONTAINER(mainvbox), GTK_WIDGET(vlist->data));
		vlist = vlist->next;
	}	
	
	a = gtk_ui_manager_get_action(ui_manager, "/MainMenu/ViewMenu/Menus");
	if(gtk_toggle_action_get_active(GTK_TOGGLE_ACTION(a))) {
		gtk_box_pack_start(GTK_BOX(mainvbox), menubar, FALSE, FALSE, 0);
	}

	vlist = gtk_container_get_children(GTK_CONTAINER(ctable));
	while(vlist) {
		g_object_ref(vlist->data);
		gtk_container_remove(GTK_CONTAINER(ctable), GTK_WIDGET(vlist->data));
		vlist = vlist->next;
	}
	gtk_table_attach(GTK_TABLE(ctable), canvasarea, 0, 1, 0, 1,
		     GTK_EXPAND | GTK_FILL | GTK_SHRINK, 
			 GTK_EXPAND | GTK_FILL | GTK_SHRINK, 0, 0);
	a = gtk_ui_manager_get_action(ui_manager, "/MainMenu/ViewMenu/Scrolls");
	if(gtk_toggle_action_get_active(GTK_TOGGLE_ACTION(a))) {
		gtk_table_attach(GTK_TABLE(ctable), vscrollbar, 1, 2, 0, 1,
		     	GTK_EXPAND | GTK_FILL | GTK_SHRINK,
			 	GTK_EXPAND | GTK_FILL | GTK_SHRINK, 0, 0);
		gtk_table_attach(GTK_TABLE(ctable), hscrollbar, 0, 1, 1, 2,
		     	GTK_EXPAND | GTK_FILL | GTK_SHRINK, 
			 	GTK_EXPAND | GTK_FILL | GTK_SHRINK, 0, 0);
	}
		
	vlist = gtk_container_get_children(GTK_CONTAINER(mainvpane));
	while(vlist) {
		g_object_ref(vlist->data);
		gtk_container_remove(GTK_CONTAINER(mainvpane), GTK_WIDGET(vlist->data));
		vlist = vlist->next;
	}
	
	a = gtk_ui_manager_get_action(ui_manager, "/MainMenu/ViewMenu/Command");
	if(gtk_toggle_action_get_active(GTK_TOGGLE_ACTION(a))) {
		gtk_window_get_size(GTK_WINDOW(mainwin), &x, &y);
		gtk_paned_set_position(GTK_PANED(mainvpane), y-200);
		gtk_paned_pack1(GTK_PANED(mainvpane), ctable, TRUE, TRUE);
		gtk_paned_pack2(GTK_PANED(mainvpane), termhbox, FALSE, TRUE);
		gtk_box_pack_start(GTK_BOX(mainvbox), mainvpane, TRUE, TRUE, 0);
	} else {
		gtk_box_pack_start(GTK_BOX(mainvbox), ctable, TRUE, TRUE, 0);
	}	  
	gtk_adjustment_value_changed(VTE_TERMINAL(vte)->adjustment);
    gtk_widget_show_all (mainvbox);
	
	a = gtk_ui_manager_get_action(ui_manager, "/MainMenu/ViewMenu/Fullscreen");
	if(gtk_toggle_action_get_active(GTK_TOGGLE_ACTION(a))) {
		gtk_window_fullscreen(GTK_WINDOW(mainwin));
	} else {
		gtk_window_unfullscreen(GTK_WINDOW(mainwin));
	}
}


void view_cb(GtkAction *action, gpointer user_data)
{
	build_window();
}


void set_ui_elements(int mask)
{
    GtkAction* a;

    a = gtk_ui_manager_get_action(ui_manager, "/MainMenu/ViewMenu/Command");
    gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(a), mask & UI_COMMAND);
    a = gtk_ui_manager_get_action(ui_manager, "/MainMenu/ViewMenu/Scrolls");
    gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(a), mask & UI_SCROLLS);
    a = gtk_ui_manager_get_action(ui_manager, "/MainMenu/ViewMenu/Menus");
    gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(a), mask & UI_MENUS);
    a = gtk_ui_manager_get_action(ui_manager, "/MainMenu/ViewMenu/Fullscreen");
    gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(a), mask & UI_FULLSCREEN);
    build_window();
}


void setfont_cb(GtkAction *action, gpointer user_data)
{
	static char *fontname = NULL;
	GtkWidget *d;
	gint result;
	
	d = gtk_font_selection_dialog_new("Command prompt font");
	if(fontname)
		gtk_font_selection_dialog_set_font_name(GTK_FONT_SELECTION_DIALOG(d), fontname);
	
	result = gtk_dialog_run(GTK_DIALOG(d));
	if(result == GTK_RESPONSE_OK) {
		fontname = gtk_font_selection_dialog_get_font_name(GTK_FONT_SELECTION_DIALOG(d));
		vte_terminal_set_font_from_string(VTE_TERMINAL(vte), fontname); 
	}
	gtk_widget_destroy (d);
}

void recent_cb(GtkAction *recent, gpointer user_data)
{
    gchar *uri;

    uri = gtk_recent_chooser_get_current_uri(GTK_RECENT_CHOOSER(recent));
    if(strncmp(uri, "file:", 5) == 0) {
        strcpy(DataFileName, uri+5);
        FetchFile(FormatPDB, False, uri+5);
        DefaultRepresentation();
        RefreshScreen();
    }
}

static const GtkActionEntry menuentries[] = {
  { "FileMenu", NULL, "_File" },
  { "Open", GTK_STOCK_OPEN, "_Open...", "<control>O", "Open a file", G_CALLBACK(open_cb) },
  { "SaveAs", GTK_STOCK_SAVE_AS, "_Save As...", "<control>S", "Save a file", G_CALLBACK(save_cb) }, 
  { "Export", GTK_STOCK_CONVERT, "_Export...", "<control>X", "Export current image", G_CALLBACK(export_cb) },
  { "Close", GTK_STOCK_CLOSE, "_Close", "<control>W", "Close the selected molecule", NULL },
  { "PageSetup", NULL, "Page Set_up...", "", "Set the page parameters", G_CALLBACK(pagesetup_cb) },
  { "Print", GTK_STOCK_PRINT, "_Print...", "<control>P", "Print the current image", G_CALLBACK(print_cb) },
  { "Exit", GTK_STOCK_QUIT, "E_xit", "<control>Q", "Exit the program", RasMolExit },
  { "ViewMenu", NULL, "_View" },
  { "Setfont", NULL, "Set command font...", "", "", G_CALLBACK(setfont_cb) },
  { "DispMenu", NULL, "_Display" },
  { "Wireframe", NULL, "_Wireframe", "", "", NULL },
  { "Backbone", NULL, "_Backbone", "", "", NULL },
  { "Sticks", NULL, "S_ticks", "", "", NULL },
  { "Spheres", NULL, "_Spacefill", "", "", NULL},
  { "Ballstick", NULL, "B_all & stick", "", "", NULL },
  { "Ribbons", NULL, "_Ribbons", "", "", NULL },
  { "Strands", NULL, "Stran_ds", "", "", NULL },
  { "Cartoons", NULL, "_Cartoons", "", "", NULL },
  { "MolSurf", NULL, "_Molecular Surface", "", "", NULL },
  { "ColMenu", NULL, "_Colours" },
  { "Monochrome", NULL, "_Monochrome", "", "", NULL },
  { "CPK", NULL, "_CPK", "", "", NULL },
  { "Shapely", NULL, "_Shapely", "", "", NULL },
  { "Group", NULL, "_Group", "", "", NULL },
  { "Chain", NULL, "C_hain", "", "", NULL },
  { "Temperature", NULL, "_Temperature", "", "", NULL },
  { "Structure", NULL, "St_ructure", "", "", NULL },
  { "User", NULL, "_User", "", "", NULL },
  { "Model", NULL, "Mo_del", "", "", NULL },
  { "Alt", NULL, "_Alt", "", "", NULL },
  { "OptMenu", NULL, "_Options" },
  { "SetMenu", NULL, "_Settings" },
  { "HelpMenu", NULL, "_Help" },
  { "Manual", GTK_STOCK_HELP, "_User Manual", "F1", "", NULL },
  { "Register", NULL, "_Register", "", "", NULL },
  { "Donate", NULL, "_Donate", "", "", NULL },
  { "About", GTK_STOCK_ABOUT, "_About", "", "", G_CALLBACK(about_cb) },
};

static const GtkToggleActionEntry view_toggles[] = {
  { "Command", NULL, "_Command prompt", "F7", "", NULL, FALSE },
  { "Scrolls", NULL, "_Scrollbars", "F8", "", NULL, FALSE },
  { "Menus",   NULL, "_Menubar", "F9", "", NULL, TRUE },
  { "Fullscreen",   NULL, "_Full Screen", "F11", "", NULL, FALSE },
};

static const GtkToggleActionEntry opt_toggles[] = {
  { "Slab", NULL, "_Slab Mode", "", "", NULL, FALSE },
  { "Hydrogens", NULL, "Hy_drogens", "", "", NULL, FALSE },
  { "Heteros", NULL, "He_tero Atoms", "", "", NULL, FALSE },
  { "Specular", NULL, "Spe_cular", "", "", NULL, FALSE },
  { "Shadows", NULL, "S_hadows", "", "", NULL, FALSE },
  { "Stereo", NULL, "Stere_o", "", "", NULL, FALSE },
  { "Labels", NULL, "_Labels", "", "", NULL, FALSE }
};

static const GtkRadioActionEntry pick_radios[] = {
  { "POff", NULL, "Pick _Off", "", "", m_s_poff },  
  { "PIdent", NULL, "Pick _Ident", "", "", m_s_pident },  
  { "PDistance", NULL, "Pick _Distance", "", "", m_s_pdist },  
  { "PMonitor", NULL, "_Pick Monitor", "", "", m_s_pmon },  
  { "PAngle", NULL, "Pick _Angle", "", "", m_s_pangle },  
  { "PTorsion", NULL, "Pick _Torsion", "", "", m_s_ptorsion },  
  { "PLabel", NULL, "Pick _Label", "", "", m_s_plabel },  
  { "PCentre", NULL, "Pick _Centre", "", "", m_s_pcentre },  
  { "PCoord", NULL, "Pick C_oord", "", "", m_s_pcoord },  
  { "PBond", NULL, "Pick _Bond", "", "", m_s_pbond },   
};
	
static const GtkRadioActionEntry rot_radios[] = {
  { "RBond", NULL, "_Rotate Bond ", "", "", m_s_rbond },  
  { "RMol", NULL, "Rotate _Mol ", "", "", m_s_rmol },  
  { "RAll", NULL, "Rotate _All ", "", "", m_s_rall },  
};

GtkActionGroup *ofiles_group;

void EnableRotBondMenu(int rot_enable) 
{
	GtkAction *a;
	
	a = gtk_ui_manager_get_action(ui_manager, "/MainMenu/SetMenu/RBond");
	if(rot_enable) {
		gtk_action_set_sensitive(a, TRUE);
	} else {
		if(gtk_toggle_action_get_active((GtkToggleAction *) a))
			gtk_toggle_action_set_active((GtkToggleAction *) gtk_ui_manager_get_action(ui_manager, "/MainMenu/SetMenu/RMol"), TRUE);
		gtk_action_set_sensitive(a, FALSE);
	}
}

void set_gtk_open_file(int index)
{
    GList *alist;
    GtkRadioAction *radact;

    alist = gtk_action_group_list_actions(ofiles_group);
    if(alist && alist->data) {
        radact = (GtkRadioAction *) alist->data;
        g_signal_handlers_block_by_func(radact, radio_cb, NULL);
        gtk_radio_action_set_current_value(radact, m_ofiles + index);
        g_signal_handlers_unblock_by_func(radact, radio_cb, NULL);
    }
    g_list_free(alist);
}


void UpdateGtkMoleculeList(void) 
{
    int i;
    char itemname[4];
    char itlabel[2*MAX_MOLNAME+1];
    GList *alist, *ahead;
    GSList *group = NULL;
    GtkRadioAction *rad;
    GError *err = NULL;
    GRegex *re = NULL;

    gtk_ui_manager_remove_ui(ui_manager, merge_id);
    merge_id = gtk_ui_manager_new_merge_id(ui_manager);

    alist = gtk_action_group_list_actions (ofiles_group);
    ahead = alist;
    while(alist) {
        gtk_action_group_remove_action(ofiles_group,
                                       (GtkAction *) alist->data);
        alist = alist->next;
    }
    g_list_free(ahead);

    itlabel[2*MAX_MOLNAME] = '\0';
    re = g_regex_new("[_]", 0, 0, &err);
    for(i = 0; i < NumMolecules; i++) {
        gchar *rep;
        // GTK menu labels use the underscore for accelerator, replace w. __
        rep = g_regex_replace_literal(re, MolNStr[i], -1, 0, "__", 0, &err);
        strncpy((itlabel+1), rep, 2*MAX_MOLNAME);
        g_free(rep);
        itlabel[0] = '_';
        snprintf(itemname, 3, "%d", i);
        rad = gtk_radio_action_new(itemname, itlabel, NULL, NULL,
                                   (m_ofiles + i));
        gtk_radio_action_set_group (rad, group);
        group = gtk_radio_action_get_group(rad);
        if (i == MoleculeIndex)
            gtk_toggle_action_set_active (GTK_TOGGLE_ACTION (rad), TRUE);
        gtk_action_group_add_action(ofiles_group, (GtkAction *) rad);
        g_object_unref(rad);
    }
    g_regex_unref(re);

    alist = gtk_action_group_list_actions(ofiles_group);
    if(alist) {
        g_signal_connect(alist->data, "changed", G_CALLBACK (radio_cb), NULL);
    }
    g_list_free(alist);

    for(i = 0; i < NumMolecules; i++) {
        snprintf(itemname, 3, "%d", i);
        gtk_ui_manager_add_ui(ui_manager, merge_id,
                              "/MainMenu/FileMenu/OFiles", itemname,
                              itemname, GTK_UI_MANAGER_MENUITEM, FALSE);
        gtk_ui_manager_add_ui(ui_manager, merge_id, "/popup/OFiles",
                              itemname, itemname,
                              GTK_UI_MANAGER_MENUITEM, FALSE);
    }

    gtk_ui_manager_ensure_update (ui_manager);
}


GtkWidget *build_gtkmenu(void)
{
    GError *error;
    GtkAction *recentaction = NULL;
    GtkRecentFilter *filter = NULL;
    int i;

    action_group = gtk_action_group_new("MenuActions");
    gtk_action_group_add_actions(action_group, menuentries,
                                  G_N_ELEMENTS(menuentries), NULL);

    recentaction = gtk_recent_action_new("Recent", "Open _Recent",
                                         "Open a recently opened file", NULL);
    filter = gtk_recent_filter_new();
    gtk_recent_filter_add_application(filter, "RasMol");
    gtk_recent_chooser_set_filter(GTK_RECENT_CHOOSER(recentaction), filter);
    gtk_recent_chooser_set_local_only(GTK_RECENT_CHOOSER(recentaction), TRUE);
    gtk_recent_chooser_set_sort_type(GTK_RECENT_CHOOSER(recentaction),
                                     GTK_RECENT_SORT_MRU);
    gtk_recent_chooser_set_limit(GTK_RECENT_CHOOSER(recentaction), 30);
    g_signal_connect(GTK_RECENT_CHOOSER(recentaction), "item-activated",
                     G_CALLBACK(recent_cb), NULL);
    gtk_action_group_add_action(action_group, recentaction);

    gtk_action_group_add_toggle_actions(action_group, view_toggles,
                                        G_N_ELEMENTS(view_toggles), NULL);
    gtk_action_group_add_toggle_actions(action_group, opt_toggles,
                                        G_N_ELEMENTS(opt_toggles), NULL);
    gtk_action_group_add_radio_actions(action_group, pick_radios,
                                       G_N_ELEMENTS(pick_radios), m_s_pident,
                                       G_CALLBACK(radio_cb), NULL);
    gtk_action_group_add_radio_actions(action_group, rot_radios,
                                       G_N_ELEMENTS(rot_radios), m_s_rmol,
                                       G_CALLBACK(radio_cb), NULL);

    ui_manager = gtk_ui_manager_new();
    gtk_ui_manager_insert_action_group(ui_manager, action_group, 0);

    accel_group = gtk_ui_manager_get_accel_group(ui_manager);
    gtk_window_add_accel_group(GTK_WINDOW(mainwin), accel_group);

    error = NULL;
    if(!gtk_ui_manager_add_ui_from_string(ui_manager, actionmenu_str,
                                          -1, &error)) {
        g_message("building menus failed: s", error->message);
        g_error_free(error);
        exit(EXIT_FAILURE);
    }

    EnableRotBondMenu(False);

    ADDSIGNAL("/MainMenu/FileMenu/Close", m_f_close);
    ADDSIGNAL("/MainMenu/DispMenu/Wireframe", m_d_wireframe);
    ADDSIGNAL("/MainMenu/DispMenu/Backbone", m_d_backbone);
    ADDSIGNAL("/MainMenu/DispMenu/Sticks", m_d_sticks);
    ADDSIGNAL("/MainMenu/DispMenu/Spheres", m_d_spheres);
    ADDSIGNAL("/MainMenu/DispMenu/Ballstick", m_d_ballstick);
    ADDSIGNAL("/MainMenu/DispMenu/Ribbons", m_d_ribbons);
    ADDSIGNAL("/MainMenu/DispMenu/Strands", m_d_strands);
    ADDSIGNAL("/MainMenu/DispMenu/Cartoons", m_d_cartoons);
    ADDSIGNAL("/MainMenu/DispMenu/MolSurf", m_d_molsurf);
    ADDSIGNAL("/MainMenu/ColMenu/Monochrome", m_c_monochrome);
    ADDSIGNAL("/MainMenu/ColMenu/CPK", m_c_cpk);
    ADDSIGNAL("/MainMenu/ColMenu/Shapely", m_c_shapely);
    ADDSIGNAL("/MainMenu/ColMenu/Group", m_c_group);
    ADDSIGNAL("/MainMenu/ColMenu/Chain", m_c_chain);
    ADDSIGNAL("/MainMenu/ColMenu/Temperature", m_c_temperature);
    ADDSIGNAL("/MainMenu/ColMenu/Structure", m_c_structure);
    ADDSIGNAL("/MainMenu/ColMenu/User", m_c_user);
    ADDSIGNAL("/MainMenu/ColMenu/Model", m_c_model);
    ADDSIGNAL("/MainMenu/ColMenu/Alt", m_c_alt);
    ADDSIGNAL("/MainMenu/OptMenu/Slab", m_o_slab);
    ADDSIGNAL("/MainMenu/OptMenu/Hydrogens", m_o_hydrogens);
    ADDSIGNAL("/MainMenu/OptMenu/Heteros", m_o_heteros);
    ADDSIGNAL("/MainMenu/OptMenu/Specular", m_o_specular);
    ADDSIGNAL("/MainMenu/OptMenu/Shadows", m_o_shadows);
    ADDSIGNAL("/MainMenu/OptMenu/Stereo", m_o_stereo);
    ADDSIGNAL("/MainMenu/OptMenu/Labels", m_o_labels);
    ADDSIGNAL("/MainMenu/HelpMenu/Manual", m_h_manual);
    ADDSIGNAL("/MainMenu/HelpMenu/Register", m_h_register);
    ADDSIGNAL("/MainMenu/HelpMenu/Donate", m_h_donate);

    g_signal_connect(gtk_ui_manager_get_action(ui_manager,"/MainMenu/ViewMenu/Command"), "activate", G_CALLBACK(view_cb), NULL);
    g_signal_connect(gtk_ui_manager_get_action(ui_manager,"/MainMenu/ViewMenu/Scrolls"), "activate", G_CALLBACK(view_cb), NULL);
    g_signal_connect(gtk_ui_manager_get_action(ui_manager,"/MainMenu/ViewMenu/Menus"), "activate", G_CALLBACK(view_cb), NULL);
    g_signal_connect(gtk_ui_manager_get_action(ui_manager,"/MainMenu/ViewMenu/Fullscreen"), "activate", G_CALLBACK(view_cb), NULL);

    /* merge id for filemenu additions */
    merge_id = gtk_ui_manager_new_merge_id(ui_manager);
    ofiles_group = gtk_action_group_new("OFileActions");
    gtk_ui_manager_insert_action_group(ui_manager, ofiles_group, 1);

    menubar = gtk_ui_manager_get_widget(ui_manager, "/MainMenu");

    return menubar;
}


static void do_popup_menu (GtkWidget *widget, GdkEventButton *event)
{
  GtkWidget *menu;
  int button, event_time;

  menu = gtk_ui_manager_get_widget(ui_manager, "/popup");
  g_signal_connect (menu, "deactivate", 
                    G_CALLBACK (gtk_widget_hide), NULL);

  if (event) {
      button = event->button;
      event_time = event->time;
  } else {
      button = 0;
      event_time = gtk_get_current_event_time ();
  }

  gtk_menu_popup (GTK_MENU (menu), NULL, NULL, NULL, NULL, 
                  0, event_time);
}
	

void AllocateColourMap( void )
{
	GdkColor Col;
    static ByteTest buf;
    register Byte temp;
    register int i;

    for( i=0; i<LutSize; i++ )
        if( ULut[i] ) {
			/* This is the correct byteorder for gdk_draw_rgb_32_image */
			Col.pixel = (RLut[i]<<24) | (GLut[i]<<16) | (BLut[i]<<8) | 0xFF;
			if( SwapBytes )
            {   buf.longword = (Long)Col.pixel;
                temp = buf.bytes[0];
                buf.bytes[0] = buf.bytes[3];
                buf.bytes[3] = temp;

                temp = buf.bytes[1];
                buf.bytes[1] = buf.bytes[2];
                buf.bytes[2] = temp;
                Lut[i] = buf.longword;
            } 
			else 
				Lut[i] = (Long)Col.pixel;
       }
}


int FetchEvent( int wait )
{
    return 0;
}

void UpdateScrollBars( void )
{
    gdouble new, old;

    if ( RotMode == RotAll ) {
		new = WorldDialValue[YScrlDial]; 
    } else {
		new = DialValue[YScrlDial];
    }
    old = gtk_range_get_value(GTK_RANGE(vscrollbar));

    if( new != old ) {
		g_signal_handler_block(G_OBJECT(vscrollbar), vscr_handler);
		gtk_range_set_value(GTK_RANGE(vscrollbar), new);
		g_signal_handler_unblock(G_OBJECT(vscrollbar), vscr_handler);
    }

    if ( (RotMode == RotBond) && BondSelected ) {
		new = BondSelected->BRotValue;
    } else {
		if ( RotMode == RotAll ) {
	    	new = WorldDialValue[XScrlDial];
		} else {
	    	new = DialValue[XScrlDial];
		}
    }
    old = gtk_range_get_value(GTK_RANGE(hscrollbar));	

    if( new != old ) {
		g_signal_handler_block(G_OBJECT(hscrollbar), hscr_handler);
		gtk_range_set_value(GTK_RANGE(hscrollbar), new);
		g_signal_handler_unblock(G_OBJECT(hscrollbar), hscr_handler);
    }

}

void EnableMenus( int flag )
{
    DisableMenu = !flag;
}

int LookUpColour( char *name, int *red, int *grn, int *blu )
{
    return False;
}


void ReDrawWindow( void )
{
	build_window();
} 


void TransferImage( void )
{
    gdk_draw_rgb_32_image (canvasarea->window,
			   canvasarea->style->fg_gc[GTK_STATE_NORMAL],
			   0, 0, XRange, YRange,
			   GDK_RGB_DITHER_NONE,
			   (guchar *) FBuffer,
			   XRange * 4);	
}

void SetMouseCaptureStatus( int bool )
{
    MouseCaptureStatus = bool;
}
                         

static int GetStatus( int mask )
{
    register int status;
    
    status = 0;                             
    if( mask & GDK_BUTTON1_MASK ) status |= MMLft;
    if( mask & GDK_BUTTON2_MASK ) status |= MMMid;
    if( mask & GDK_BUTTON3_MASK ) status |= MMRgt;
    if( mask & GDK_CONTROL_MASK ) status |= MMCtl;
    if( mask & GDK_SHIFT_MASK )   status |= MMSft;
    return status;
}


gboolean expose_cb(GtkWidget *widget, GdkEventExpose *event, gpointer user_data)
{
    TransferImage();
    return FALSE;
}


gboolean configure_cb(GtkWidget *widget, GdkEventConfigure *event, gpointer user_data)
{
	int dx;
	
    XRange = event->width;
    YRange = event->height;
	ZRange = 20000;

	if( (dx = XRange%4) )
        XRange += 4-dx;
	
	HRange = YRange>>1;	
    WRange = XRange>>1;
    Range = MinFun(XRange,YRange);
	
	gtk_widget_set_size_request(widget, XRange, YRange);
    
    ReDrawFlag |= RFReSize;
	RefreshScreen();
	ReDrawFlag = NextReDrawFlag;
	
    return FALSE;
}


void vscroll_cb(GtkRange *range, gpointer user_data)
{
    WorldDialValue[YScrlDial] = gtk_range_get_value(range);
    ReDrawFlag |= (1<<YScrlDial);
    RefreshScreen();
    ReDrawFlag = NextReDrawFlag;
}

void hscroll_cb(GtkRange *range, gpointer user_data)
{
	gdouble val;
	
	val = gtk_range_get_value(range);
	if( (RotMode == RotBond) && BondSelected ) {
          BondSelected->BRotValue =  val;
          ReDrawFlag |= RFRotBond;
	} else {
    	WorldDialValue[XScrlDial] = val;
    	ReDrawFlag |= (1<<XScrlDial);
	}
    RefreshScreen();
    ReDrawFlag = NextReDrawFlag;
}

static gboolean popup_cb (GtkWidget *widget)
{
  do_popup_menu (widget, NULL);
  return TRUE;
}

gboolean motion_cb(GtkWidget *canvas, GdkEventMotion *event, gpointer user_data)
{
    int stat, x, y, xorig, yorig;
    GdkModifierType mask;

	dragging = TRUE;
    stat = GetStatus(event->state);
    ProcessMouseMove(event->x,event->y,stat);
    if(ReDrawFlag) {
		RefreshScreen();
        ReDrawFlag = NextReDrawFlag;
    }
    xorig = event->x;
    yorig = event->y;
    gdk_window_get_pointer(canvas->window, &x, &y, &mask);

    return FALSE;
}

gboolean button_press_cb(GtkWidget *canvas, GdkEventButton *event, gpointer user_data)
{
    int stat;
	
    HeldButton = -1;
    stat = GetStatus(event->state);
    ProcessMouseDown(event->x,event->y,stat);
    return FALSE;
}

gboolean button_release_cb(GtkWidget *canvas, GdkEventButton *event, gpointer user_data)
{
    int stat;

    if (!dragging && event->button == 3 && event->type == GDK_BUTTON_RELEASE
        && !(event->state & (GDK_CONTROL_MASK | GDK_SHIFT_MASK))) {
		do_popup_menu (canvas, event);
    } else {
    	stat = GetStatus(event->state);
    	ProcessMouseUp(event->x,event->y,stat);
	}
    if( ReDrawFlag ) {
        RefreshScreen();
    }
	dragging = FALSE;
	
    return TRUE;
}


void do_char(char c) 
{
    if(ProcessCharacter(c)) {
        if(ProcessCommand())
            RasMolExit();
        if(!CommandActive) {
            ResetCommandLine(0);
            RefreshScreen();
            ReDrawFlag = NextReDrawFlag;
        }
    }	
}


void termin_cb(VteTerminal *vte, gchar *str, guint len, gpointer user_data)
{
    int i;
    gchar buf;
    static char prev = 0;

    /* Map xterm escape sequences to ASCII control chars */
    for(i = 0; i < len; i++) {
        buf = str[i];
        switch(prev) {
            case '\0':
                if(buf!=0x1b) {
                    do_char(buf);
                    prev = '\0';
                } else {
                    prev = 0x1b;
                }
                break;
            case 0x1b:
                if( (buf!='[') && (buf!='O') ) {
                    do_char(buf);
                    prev = '\0';
                } else {
                    prev = buf;
                }
                break;
            case '[':
            case 'O':
                switch( buf ) {
                    /* Arrow keys */
                    case('A'): do_char(0x10); break;
                    case('B'): do_char(0x0e); break;
                    case('C'): do_char(0x06); break;
                    case('D'): do_char(0x02); break;
                    /* Delete */
                    case('3'): do_char(0x04); i++; break;
                    /* Ignore the rest */
                    default:
                        i = len;
                }
                prev = '\0';
        }
    }
}


void WriteChar(int ch)
{
    char buf[3];

    switch(ch) {
        case('\n'):
            buf[0] = '\n';
            buf[1] = '\r';
            buf[2] = '\0';
            vte_terminal_feed(VTE_TERMINAL(vte), buf, 2);
            break;
        default:
            buf[0] = ch;
            buf[1] = '\0';
            vte_terminal_feed(VTE_TERMINAL(vte), buf, 1);
    }
}


void WriteString(char *ptr)
{
    while(*ptr)
        WriteChar(*ptr++);
}


int OpenDisplay(void)
{
#ifdef THIRTYTWOBIT
    static ByteTest test;
#endif
    int i;
    static char VersionStr[50];
    GError *gerr = NULL;

    sprintf (VersionStr,"RasMol Version %s", VERSION);

    for( i=0; i<11; i++ )
        DialValue[i] = 0.0;

    RLut[0]=0;   GLut[0]=0;   BLut[0]=0;    ULut[0]=True;
    RLut[1]=100; GLut[1]=100; BLut[1]=100;  ULut[1]=True;
    RLut[2]=150; GLut[2]=150; BLut[2]=150;  ULut[2]=True;
    RLut[3]=200; GLut[3]=200; BLut[3]=200;  ULut[3]=True;
    RLut[4]=255; GLut[4]=255; BLut[4]=255;  ULut[4]=True;

    XRange = DefaultWide;
    YRange = DefaultHigh;
    if (InitWidth  >= RASGTK_MINWIDTH) XRange = InitWidth;
    if (InitHeight >= RASGTK_MINHEIGHT) YRange = InitHeight;
    WRange = XRange>>1;
    HRange = YRange>>1;
    Range = MinFun(XRange,YRange);

    if( !Interactive )
        return( False );

    g_set_application_name("RasMol");
    mainwin = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_add_events(mainwin, GDK_KEY_PRESS_MASK);
    g_signal_connect (mainwin, "delete-event",
        G_CALLBACK (RasMolExit), NULL);

    menubar = build_gtkmenu();

    mainvbox = gtk_vbox_new(FALSE, 0);

    ctable = gtk_table_new(2, 2, FALSE);   

    canvasarea = gtk_drawing_area_new();
    gtk_widget_add_events(canvasarea, GDK_POINTER_MOTION_HINT_MASK);
    gtk_widget_add_events(canvasarea, GDK_BUTTON_PRESS_MASK);
    gtk_widget_add_events(canvasarea, GDK_BUTTON_RELEASE_MASK);    
    gtk_widget_add_events(canvasarea, GDK_BUTTON_MOTION_MASK);        
    g_signal_connect (G_OBJECT (canvasarea), "expose-event",  
        G_CALLBACK (expose_cb), NULL);
    g_signal_connect (G_OBJECT (canvasarea), "configure-event",  
        G_CALLBACK (configure_cb), NULL);
    g_signal_connect (G_OBJECT (canvasarea), "motion-notify-event",  
        G_CALLBACK (motion_cb), NULL);
    g_signal_connect (G_OBJECT (canvasarea), "button-press-event",  
        G_CALLBACK (button_press_cb), NULL);
    g_signal_connect (G_OBJECT (canvasarea), "button-release-event",  
        G_CALLBACK (button_release_cb), NULL);
    g_signal_connect (G_OBJECT (canvasarea), "popup-menu",  
        G_CALLBACK (popup_cb), NULL);

    vscrollbar = gtk_vscrollbar_new(NULL);
    gtk_range_set_update_policy(GTK_RANGE(vscrollbar),
        GTK_UPDATE_CONTINUOUS);
    gtk_range_set_range(GTK_RANGE(vscrollbar), -1.0, 1.0);
    gtk_range_set_increments(GTK_RANGE(vscrollbar), 0.01, 0.1);
    vscr_handler = g_signal_connect(G_OBJECT(vscrollbar), "value-changed",
        G_CALLBACK(vscroll_cb), NULL);

    hscrollbar = gtk_hscrollbar_new(NULL);
    gtk_range_set_update_policy(GTK_RANGE(hscrollbar),
        GTK_UPDATE_CONTINUOUS);
    gtk_range_set_range(GTK_RANGE(hscrollbar), -1.0, 1.0);
    gtk_range_set_increments(GTK_RANGE(hscrollbar), 0.01, 0.1);
    hscr_handler = g_signal_connect(G_OBJECT(hscrollbar), "value-changed",
				    G_CALLBACK(hscroll_cb), NULL);

    vte = vte_terminal_new();
    g_assert(vte);
    vte_terminal_set_size(VTE_TERMINAL(vte), 80, 10);
    vte_terminal_set_font_from_string(VTE_TERMINAL(vte), "Monospace 10");
    vte_terminal_set_scroll_on_output(VTE_TERMINAL(vte), TRUE);
    vte_terminal_set_backspace_binding(VTE_TERMINAL(vte), VTE_ERASE_ASCII_BACKSPACE);
    vte_terminal_set_delete_binding(VTE_TERMINAL(vte), VTE_ERASE_DELETE_SEQUENCE);
    g_signal_connect(G_OBJECT(vte), "commit", G_CALLBACK(termin_cb), NULL);

    termhbox = gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(termhbox), vte, TRUE, TRUE, 0);

    GtkWidget *termscroll;
    termscroll = gtk_vscrollbar_new(VTE_TERMINAL(vte)->adjustment);
    gtk_box_pack_start(GTK_BOX(termhbox), termscroll, FALSE, FALSE, 0);

    mainvpane = gtk_vpaned_new();

    build_window();

    GdkGeometry geo;
    geo.min_width = RASGTK_MINWIDTH;
    geo.min_height = RASGTK_MINHEIGHT;
    gtk_window_set_geometry_hints(GTK_WINDOW(mainwin), GTK_WIDGET(mainvbox),
        &geo, GDK_HINT_MIN_SIZE);
    gtk_window_set_default_icon(gdk_pixbuf_from_pixdata(&rasmol_icon,
                                                        TRUE, &gerr));

    gtk_container_add (GTK_CONTAINER (mainwin), mainvbox);
    gtk_widget_set_size_request(mainwin, XRange, YRange);
    gtk_widget_show_all (mainwin);

    test.longword = (Long)0x000000ff;    
    SwapBytes = test.bytes[0];

    return True;
}


int CreateImage( void )
{
    long size;

    if(FBuffer) {
		_ffree(FBuffer);
    }
	size = (long)XRange*YRange*sizeof(Pixel);
	FBuffer = (Pixel*)_fmalloc( size+32 );
	
	return((FBuffer!=(Pixel*)NULL)?True : False);
}


void ClearImage( void )
{

}


int PrintImage( void )
{
    return False;
}


int ClipboardImage( void )
{
    return False;
}


void SetCanvasTitle( char *ptr )
{
	if( Interactive ) { 
    	gtk_window_set_title(GTK_WINDOW(mainwin), ptr); 
    } 
}


void SetMouseUpdateStatus( int bool )
{
    MouseUpdateStatus = bool;
}


void BeginWait( void )
{

}


void EndWait( void )
{

}


void CloseDisplay( void )
{

}


void RasMolExit( void )
{
    gtk_main_quit();
    exit(0);
}


void RasMolFatalExit( char *msg )
{
    putc('\n', stdout);
    fputs(msg, stdout);
    putc('\n', stdout);
    gtk_main_quit();
    exit(1);
}
