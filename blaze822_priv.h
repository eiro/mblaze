struct message {
	char *msg;
	char *end;
	char *body;
	char *bodyend;
	char *bodychunk;
	char *orig_header;
};

//          WSP            =  SP / HTAB
#define iswsp(c)  (((c) == ' ' || (c) == '\t'))

#define isfws(c) \
	(( (unsigned char)(c) == ' '  \
	|| (unsigned char)(c) == '\t' \
	|| (unsigned char)(c) == '\n' \
	|| (unsigned char)(c) == '\r' ))

// ASCII lowercase without alpha check (wrong for "@[\]^_")
#define lc(c) ((c) | 0x20)
#define uc(c) ((c) & 0xdf)

#if defined(DT_REG) && defined(DT_LNK) && defined(DT_UNKNOWN)
#define IS_LEGIT_DT(t) (t != DT_REG && t != DT_LNK && t != DT_UNKNOWN)
#else
#define IS_LEGIT_DT(t) (1)
#endif

void *mymemmem(const void *h0, size_t k, const void *n0, size_t l);
