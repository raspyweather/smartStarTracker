#define ARCSECS_PER_ARCMIN 60
#define ARCMIN_PER_DEG 60
#define DEG_PER_ROT 360


#define DEG_TO_ARCSEC(value) (value * ARCMIN_PER_DEG * ARCSECS_PER_ARCMIN)

#define MS_TO_SEC(value) (value * 1000)
#define MS_TO_MIN(value) (MS_TO_SEC(value) * 60)