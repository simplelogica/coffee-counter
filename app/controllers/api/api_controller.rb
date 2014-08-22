include ActionController::HttpAuthentication::Token::ControllerMethods
include ActionController::MimeResponds

module Api
  class ApiController < ActionController::API
    include Concerns::Restricted

    def index
      render json: {message: 'Resource not found'}, status: 404
    end
  end
end
