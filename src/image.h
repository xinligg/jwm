/**
 * @file image.h
 * @author Joe Wingbermuehle
 * @date 2005-2006
 *
 * @brief Functions to load images.
 *
 */

#ifndef IMAGE_H
#define IMAGE_H

/** Structure to represent an image. */
typedef struct ImageNode {

#ifdef USE_PNG
   png_uint_32 width;       /**< Width of the image. */
   png_uint_32 height;      /**< Height of the image. */
#else
   int width;               /**< Width of the image. */
   int height;              /**< Height of the image. */
#endif

   unsigned long *data;     /**< Image data. */

} ImageNode;

/** Load an image from a file.
 * @param fileName The file containing the image.
 * @return A new image node (NULL if the image could not be loaded).
 */
ImageNode *LoadImage(const char *fileName);

/** Load an image from data.
 * The data must be in the format from the EWMH spec.
 * @param data The image data.
 * @return A new image node (NULL if there were errors.
 */
ImageNode *LoadImageFromData(char **data);

/** Destroy an image node.
 * @param image The image to destroy.
 */
void DestroyImage(ImageNode *image);

#endif /* IMAGE_H */

