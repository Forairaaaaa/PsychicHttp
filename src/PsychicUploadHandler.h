#ifndef PsychicUploadHandler_h
#define PsychicUploadHandler_h

#include "PsychicCore.h"
#include "PsychicHttpServer.h"
#include "PsychicHttpServerRequest.h"
#include "PsychicWebHandler.h"

//callback definitions
typedef std::function<esp_err_t(PsychicHttpServerRequest *request, const String& filename, uint64_t index, uint8_t *data, size_t len, bool final)> PsychicUploadCallback;

/*
* HANDLER :: Can be attached to any endpoint or as a generic request handler.
*/

class PsychicUploadHandler : public PsychicWebHandler {
  protected:
    PsychicUploadCallback _uploadCallback;

    PsychicHttpServerRequest *_request;

    String _temp;
    uint8_t _parseState;
    size_t _parsedLength;
    uint8_t _multiParseState;
    String _boundary;
    uint8_t _boundaryPosition;
    size_t _itemStartIndex;
    size_t _itemSize;
    String _itemName;
    String _itemFilename;
    String _itemType;
    String _itemValue;
    uint8_t *_itemBuffer;
    size_t _itemBufferIndex;
    bool _itemIsFile;

    esp_err_t _basicUploadHandler(PsychicHttpServerRequest *request);
    esp_err_t _multipartUploadHandler(PsychicHttpServerRequest *request);

    void _handleUploadByte(uint8_t data, bool last);
    void _parseMultipartPostByte(uint8_t data, bool last);

  public:
    PsychicUploadHandler();
    ~PsychicUploadHandler();

    bool canHandle(PsychicHttpServerRequest *request) override;
    esp_err_t handleRequest(PsychicHttpServerRequest *request) override;

    PsychicUploadHandler * onUpload(PsychicUploadCallback fn);
};

#endif // PsychicUploadHandler_h